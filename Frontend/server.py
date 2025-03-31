import http.server
import socketserver
import os

PORT = 8000

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

with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print(f"Serving at http://localhost:{PORT}")
    print("Press Ctrl+C to stop")
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("\nServer stopped")