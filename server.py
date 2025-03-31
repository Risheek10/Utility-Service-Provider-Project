import http.server
import socketserver
import os

PORT = 8000

class MyCGIServer(socketserver.TCPServer):
    def __init__(self, server_address, handler_class):
        super().__init__(server_address, handler_class)
        self.server_name = "localhost"  # Added server_name
        self.server_port = server_address[1]  # Added server_port

class Handler(http.server.CGIHTTPRequestHandler):
    cgi_directories = ["/cgi-bin"]

# Create required directories
os.makedirs("cgi-bin", exist_ok=True)

# Make sure the CGI binary is executable (Unix-like systems)
if not os.path.exists("cgi-bin/billing.cgi"):
    # Copy or symlink your compiled binary
    if os.path.exists("billing"):
        os.symlink("../billing", "cgi-bin/billing.cgi")
    os.chmod("cgi-bin/billing.cgi", 0o755)

with MyCGIServer(("", PORT), Handler) as httpd:
    print(f"Serving at http://localhost:{PORT}")
    print("Press Ctrl+C to stop")
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("\nServer stopped")
