#include "data.h"

using namespace std;

// Define 10 utility service providers, each offering 8 services
vector<Provider> providers = {
    {
        0, "EcoEnergy Corp", {
            {"Natural Gas", {"Natural Gas", 12.00, 0.18}},
            {"Internet", {"Internet", 15.00, 0.10}},
            {"TV", {"TV", 10.00, 0.05}},
            {"Mobile Phone", {"Mobile Phone", 5.00, 0.08}},
            {"Home Phone", {"Home Phone", 4.00, 0.04}},
            {"Electric", {"Electric", 20.00, 0.22}},
            {"Water", {"Water", 10.00, 0.14}},
            {"Sewerage", {"Sewerage", 8.00, 0.11}}
        }
    },
    {
        1, "GreenFlow Utilities", {
            {"Natural Gas", {"Natural Gas", 13.50, 0.19}},
            {"Internet", {"Internet", 12.00, 0.12}},
            {"TV", {"TV", 12.00, 0.06}},
            {"Mobile Phone", {"Mobile Phone", 6.00, 0.09}},
            {"Home Phone", {"Home Phone", 3.00, 0.03}},
            {"Electric", {"Electric", 18.00, 0.20}},
            {"Water", {"Water", 9.00, 0.13}},
            {"Sewerage", {"Sewerage", 7.50, 0.10}}
        }
    },
    {
        2, "MetroGrid Solutions", {
            {"Natural Gas", {"Natural Gas", 14.00, 0.21}},
            {"Internet", {"Internet", 17.00, 0.11}},
            {"TV", {"TV", 11.00, 0.06}},
            {"Mobile Phone", {"Mobile Phone", 4.00, 0.07}},
            {"Home Phone", {"Home Phone", 3.50, 0.05}},
            {"Electric", {"Electric", 21.00, 0.23}},
            {"Water", {"Water", 10.00, 0.15}},
            {"Sewerage", {"Sewerage", 7.00, 0.09}}
        }
    },
    {
        3, "Sunrise Utilities", {
            {"Natural Gas", {"Natural Gas", 10.00, 0.16}},
            {"Internet", {"Internet", 18.00, 0.14}},
            {"TV", {"TV", 13.00, 0.07}},
            {"Mobile Phone", {"Mobile Phone", 7.00, 0.10}},
            {"Home Phone", {"Home Phone", 6.00, 0.06}},
            {"Electric", {"Electric", 19.00, 0.21}},
            {"Water", {"Water", 11.00, 0.16}},
            {"Sewerage", {"Sewerage", 6.00, 0.08}}
        }
    },
    {
        4, "TrueSource Energy", {
            {"Natural Gas", {"Natural Gas", 11.50, 0.17}},
            {"Internet", {"Internet", 14.00, 0.10}},
            {"TV", {"TV", 9.00, 0.04}},
            {"Mobile Phone", {"Mobile Phone", 5.50, 0.08}},
            {"Home Phone", {"Home Phone", 4.50, 0.04}},
            {"Electric", {"Electric", 22.00, 0.24}},
            {"Water", {"Water", 10.00, 0.14}},
            {"Sewerage", {"Sewerage", 8.50, 0.12}}
        }
    },
    {
        5, "PowerNet Utilities", {
            {"Natural Gas", {"Natural Gas", 12.50, 0.20}},
            {"Internet", {"Internet", 13.00, 0.09}},
            {"TV", {"TV", 10.00, 0.05}},
            {"Mobile Phone", {"Mobile Phone", 6.50, 0.09}},
            {"Home Phone", {"Home Phone", 5.00, 0.05}},
            {"Electric", {"Electric", 20.00, 0.22}},
            {"Water", {"Water", 9.50, 0.13}},
            {"Sewerage", {"Sewerage", 7.50, 0.10}}
        }
    },
    {
        6, "Skyline Services", {
            {"Natural Gas", {"Natural Gas", 13.00, 0.18}},
            {"Internet", {"Internet", 16.00, 0.13}},
            {"TV", {"TV", 11.00, 0.06}},
            {"Mobile Phone", {"Mobile Phone", 6.00, 0.08}},
            {"Home Phone", {"Home Phone", 4.00, 0.05}},
            {"Electric", {"Electric", 19.00, 0.21}},
            {"Water", {"Water", 10.00, 0.14}},
            {"Sewerage", {"Sewerage", 8.00, 0.11}}
        }
    },
    {
        7, "NorthGrid Inc.", {
            {"Natural Gas", {"Natural Gas", 14.00, 0.22}},
            {"Internet", {"Internet", 12.00, 0.10}},
            {"TV", {"TV", 10.00, 0.05}},
            {"Mobile Phone", {"Mobile Phone", 5.00, 0.07}},
            {"Home Phone", {"Home Phone", 3.00, 0.03}},
            {"Electric", {"Electric", 21.00, 0.23}},
            {"Water", {"Water", 11.00, 0.15}},
            {"Sewerage", {"Sewerage", 9.00, 0.12}}
        }
    },
    {
        8, "Vertex Utilities", {
            {"Natural Gas", {"Natural Gas", 13.50, 0.20}},
            {"Internet", {"Internet", 15.00, 0.11}},
            {"TV", {"TV", 12.00, 0.07}},
            {"Mobile Phone", {"Mobile Phone", 6.00, 0.09}},
            {"Home Phone", {"Home Phone", 4.50, 0.05}},
            {"Electric", {"Electric", 22.00, 0.25}},
            {"Water", {"Water", 10.00, 0.13}},
            {"Sewerage", {"Sewerage", 8.50, 0.11}}
        }
    },
    {
        9, "Allied Utility Group", {
            {"Natural Gas", {"Natural Gas", 12.00, 0.19}},
            {"Internet", {"Internet", 13.00, 0.10}},
            {"TV", {"TV", 11.00, 0.06}},
            {"Mobile Phone", {"Mobile Phone", 5.50, 0.08}},
            {"Home Phone", {"Home Phone", 3.50, 0.04}},
            {"Electric", {"Electric", 20.00, 0.22}},
            {"Water", {"Water", 9.00, 0.12}},
            {"Sewerage", {"Sewerage", 7.00, 0.09}}
        }
    }
};

// Initialize customers list (to be filled in batches)
vector<Customer> customers = {
    {
        1, "Alice Smith", "alice.smith@example.com", "101 Oak Street",
        {{"Electric", 120}, {"Water", 50}, {"Internet", 200}, {"TV", 150}, {"Mobile Phone", 300}, {"Home Phone", 100}, {"Natural Gas", 80}, {"Sewerage", 40}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        2, "Bob Johnson", "bob.johnson@example.com", "202 Pine Avenue",
        {{"Electric", 100}, {"Water", 40}, {"Internet", 150}, {"TV", 80}, {"Mobile Phone", 250}, {"Home Phone", 60}, {"Natural Gas", 70}, {"Sewerage", 35}},
        {{"Electric", 1}, {"Water", 1}, {"Internet", 1}, {"TV", 1}, {"Mobile Phone", 1}, {"Home Phone", 1}, {"Natural Gas", 1}, {"Sewerage", 1}},
        0.0
    },
    {
        3, "Catherine Lee", "catherine.lee@example.com", "303 Maple Road",
        {{"Electric", 110}, {"Water", 55}, {"Internet", 180}, {"TV", 100}, {"Mobile Phone", 280}, {"Home Phone", 90}, {"Natural Gas", 75}, {"Sewerage", 45}},
        {{"Electric", 2}, {"Water", 2}, {"Internet", 2}, {"TV", 2}, {"Mobile Phone", 2}, {"Home Phone", 2}, {"Natural Gas", 2}, {"Sewerage", 2}},
        0.0
    },
    {
        4, "Daniel Kim", "daniel.kim@example.com", "404 Birch Blvd",
        {{"Electric", 90}, {"Water", 35}, {"Internet", 220}, {"TV", 160}, {"Mobile Phone", 330}, {"Home Phone", 110}, {"Natural Gas", 85}, {"Sewerage", 38}},
        {{"Electric", 3}, {"Water", 3}, {"Internet", 3}, {"TV", 3}, {"Mobile Phone", 3}, {"Home Phone", 3}, {"Natural Gas", 3}, {"Sewerage", 3}},
        0.0
    },
    {
        5, "Ella Martinez", "ella.martinez@example.com", "505 Cedar Crescent",
        {{"Electric", 95}, {"Water", 42}, {"Internet", 190}, {"TV", 90}, {"Mobile Phone", 290}, {"Home Phone", 95}, {"Natural Gas", 82}, {"Sewerage", 36}},
        {{"Electric", 4}, {"Water", 4}, {"Internet", 4}, {"TV", 4}, {"Mobile Phone", 4}, {"Home Phone", 4}, {"Natural Gas", 4}, {"Sewerage", 4}},
        0.0
    },
    {
        6, "Frank Turner", "frank.turner@example.com", "606 Aspen Way",
        {{"Electric", 105}, {"Water", 48}, {"Internet", 210}, {"TV", 140}, {"Mobile Phone", 310}, {"Home Phone", 105}, {"Natural Gas", 78}, {"Sewerage", 42}},
        {{"Electric", 5}, {"Water", 5}, {"Internet", 5}, {"TV", 5}, {"Mobile Phone", 5}, {"Home Phone", 5}, {"Natural Gas", 5}, {"Sewerage", 5}},
        0.0
    },
    {
        7, "Grace Chen", "grace.chen@example.com", "707 Willow Lane",
        {{"Electric", 88}, {"Water", 33}, {"Internet", 160}, {"TV", 110}, {"Mobile Phone", 270}, {"Home Phone", 70}, {"Natural Gas", 69}, {"Sewerage", 30}},
        {{"Electric", 6}, {"Water", 6}, {"Internet", 6}, {"TV", 6}, {"Mobile Phone", 6}, {"Home Phone", 6}, {"Natural Gas", 6}, {"Sewerage", 6}},
        0.0
    },
    {
        8, "Henry Adams", "henry.adams@example.com", "808 Spruce Street",
        {{"Electric", 97}, {"Water", 39}, {"Internet", 175}, {"TV", 95}, {"Mobile Phone", 260}, {"Home Phone", 85}, {"Natural Gas", 73}, {"Sewerage", 37}},
        {{"Electric", 7}, {"Water", 7}, {"Internet", 7}, {"TV", 7}, {"Mobile Phone", 7}, {"Home Phone", 7}, {"Natural Gas", 7}, {"Sewerage", 7}},
        0.0
    },
    {
        9, "Isabelle Ford", "isabelle.ford@example.com", "909 Redwood Terrace",
        {{"Electric", 102}, {"Water", 47}, {"Internet", 185}, {"TV", 125}, {"Mobile Phone", 320}, {"Home Phone", 100}, {"Natural Gas", 76}, {"Sewerage", 40}},
        {{"Electric", 8}, {"Water", 8}, {"Internet", 8}, {"TV", 8}, {"Mobile Phone", 8}, {"Home Phone", 8}, {"Natural Gas", 8}, {"Sewerage", 8}},
        0.0
    },
    {
        10, "Jack Nguyen", "jack.nguyen@example.com", "1010 Elm Avenue",
        {{"Electric", 85}, {"Water", 32}, {"Internet", 145}, {"TV", 85}, {"Mobile Phone", 240}, {"Home Phone", 65}, {"Natural Gas", 65}, {"Sewerage", 28}},
        {{"Electric", 9}, {"Water", 9}, {"Internet", 9}, {"TV", 9}, {"Mobile Phone", 9}, {"Home Phone", 9}, {"Natural Gas", 9}, {"Sewerage", 9}},
        0.0
    },
    {
        11, "Katie Rivera", "katie.rivera@example.com", "11 Chestnut Rd",
        {{"Electric", 110}, {"Water", 52}, {"Internet", 200}, {"TV", 130}, {"Mobile Phone", 305}, {"Home Phone", 95}, {"Natural Gas", 81}, {"Sewerage", 43}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        12, "Leo Carter", "leo.carter@example.com", "12 Aspen Blvd",
        {{"Electric", 98}, {"Water", 40}, {"Internet", 170}, {"TV", 100}, {"Mobile Phone", 280}, {"Home Phone", 88}, {"Natural Gas", 74}, {"Sewerage", 36}},
        {{"Electric", 1}, {"Water", 2}, {"Internet", 3}, {"TV", 4}, {"Mobile Phone", 5}, {"Home Phone", 6}, {"Natural Gas", 7}, {"Sewerage", 8}},
        0.0
    },
    {
        13, "Maya Wilson", "maya.wilson@example.com", "13 Maple Way",
        {{"Electric", 92}, {"Water", 38}, {"Internet", 165}, {"TV", 90}, {"Mobile Phone", 270}, {"Home Phone", 75}, {"Natural Gas", 70}, {"Sewerage", 35}},
        {{"Electric", 2}, {"Water", 3}, {"Internet", 4}, {"TV", 5}, {"Mobile Phone", 6}, {"Home Phone", 7}, {"Natural Gas", 8}, {"Sewerage", 9}},
        0.0
    },
    {
        14, "Nathan Brooks", "nathan.brooks@example.com", "14 Cedar Ct",
        {{"Electric", 108}, {"Water", 50}, {"Internet", 190}, {"TV", 120}, {"Mobile Phone", 295}, {"Home Phone", 98}, {"Natural Gas", 79}, {"Sewerage", 39}},
        {{"Electric", 3}, {"Water", 4}, {"Internet", 5}, {"TV", 6}, {"Mobile Phone", 7}, {"Home Phone", 8}, {"Natural Gas", 9}, {"Sewerage", 0}},
        0.0
    },
    {
        15, "Olivia Parker", "olivia.parker@example.com", "15 Sycamore Lane",
        {{"Electric", 103}, {"Water", 43}, {"Internet", 185}, {"TV", 110}, {"Mobile Phone", 275}, {"Home Phone", 82}, {"Natural Gas", 72}, {"Sewerage", 33}},
        {{"Electric", 4}, {"Water", 5}, {"Internet", 6}, {"TV", 7}, {"Mobile Phone", 8}, {"Home Phone", 9}, {"Natural Gas", 0}, {"Sewerage", 1}},
        0.0
    },
    {
        16, "Patrick Singh", "patrick.singh@example.com", "16 Alder Drive",
        {{"Electric", 100}, {"Water", 41}, {"Internet", 160}, {"TV", 85}, {"Mobile Phone", 260}, {"Home Phone", 70}, {"Natural Gas", 68}, {"Sewerage", 34}},
        {{"Electric", 5}, {"Water", 6}, {"Internet", 7}, {"TV", 8}, {"Mobile Phone", 9}, {"Home Phone", 0}, {"Natural Gas", 1}, {"Sewerage", 2}},
        0.0
    },
    {
        17, "Quinn Patel", "quinn.patel@example.com", "17 Bayview Crescent",
        {{"Electric", 87}, {"Water", 36}, {"Internet", 150}, {"TV", 80}, {"Mobile Phone", 250}, {"Home Phone", 60}, {"Natural Gas", 67}, {"Sewerage", 29}},
        {{"Electric", 6}, {"Water", 7}, {"Internet", 8}, {"TV", 9}, {"Mobile Phone", 0}, {"Home Phone", 1}, {"Natural Gas", 2}, {"Sewerage", 3}},
        0.0
    },
    {
        18, "Rosa White", "rosa.white@example.com", "18 Oakridge Blvd",
        {{"Electric", 90}, {"Water", 37}, {"Internet", 140}, {"TV", 78}, {"Mobile Phone", 240}, {"Home Phone", 68}, {"Natural Gas", 66}, {"Sewerage", 30}},
        {{"Electric", 7}, {"Water", 8}, {"Internet", 9}, {"TV", 0}, {"Mobile Phone", 1}, {"Home Phone", 2}, {"Natural Gas", 3}, {"Sewerage", 4}},
        0.0
    },
    {
        19, "Sam Bennett", "sam.bennett@example.com", "19 Pine Hollow",
        {{"Electric", 104}, {"Water", 44}, {"Internet", 180}, {"TV", 110}, {"Mobile Phone", 265}, {"Home Phone", 85}, {"Natural Gas", 73}, {"Sewerage", 39}},
        {{"Electric", 8}, {"Water", 9}, {"Internet", 0}, {"TV", 1}, {"Mobile Phone", 2}, {"Home Phone", 3}, {"Natural Gas", 4}, {"Sewerage", 5}},
        0.0
    },
    {
        20, "Tina Garcia", "tina.garcia@example.com", "20 Laurel Loop",
        {{"Electric", 96}, {"Water", 38}, {"Internet", 155}, {"TV", 88}, {"Mobile Phone", 245}, {"Home Phone", 66}, {"Natural Gas", 71}, {"Sewerage", 31}},
        {{"Electric", 9}, {"Water", 0}, {"Internet", 1}, {"TV", 2}, {"Mobile Phone", 3}, {"Home Phone", 4}, {"Natural Gas", 5}, {"Sewerage", 6}},
        0.0
    },
    {
        21, "Umar Khan", "umar.khan@example.com", "21 Heather St",
        {{"Electric", 107}, {"Water", 49}, {"Internet", 175}, {"TV", 115}, {"Mobile Phone", 278}, {"Home Phone", 93}, {"Natural Gas", 76}, {"Sewerage", 39}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        22, "Vera Morales", "vera.morales@example.com", "22 Fern Hollow",
        {{"Electric", 91}, {"Water", 37}, {"Internet", 168}, {"TV", 98}, {"Mobile Phone", 254}, {"Home Phone", 75}, {"Natural Gas", 70}, {"Sewerage", 33}},
        {{"Electric", 1}, {"Water", 2}, {"Internet", 3}, {"TV", 4}, {"Mobile Phone", 5}, {"Home Phone", 6}, {"Natural Gas", 7}, {"Sewerage", 8}},
        0.0
    },
    {
        23, "William Zhang", "will.zhang@example.com", "23 Pinebrook Ct",
        {{"Electric", 99}, {"Water", 42}, {"Internet", 185}, {"TV", 105}, {"Mobile Phone", 290}, {"Home Phone", 90}, {"Natural Gas", 73}, {"Sewerage", 36}},
        {{"Electric", 2}, {"Water", 3}, {"Internet", 4}, {"TV", 5}, {"Mobile Phone", 6}, {"Home Phone", 7}, {"Natural Gas", 8}, {"Sewerage", 9}},
        0.0
    },
    {
        24, "Ximena Flores", "ximena.flores@example.com", "24 Goldenrod Ln",
        {{"Electric", 87}, {"Water", 30}, {"Internet", 150}, {"TV", 85}, {"Mobile Phone", 240}, {"Home Phone", 60}, {"Natural Gas", 67}, {"Sewerage", 28}},
        {{"Electric", 3}, {"Water", 4}, {"Internet", 5}, {"TV", 6}, {"Mobile Phone", 7}, {"Home Phone", 8}, {"Natural Gas", 9}, {"Sewerage", 0}},
        0.0
    },
    {
        25, "Yara Simmons", "yara.simmons@example.com", "25 Jasmine Trail",
        {{"Electric", 113}, {"Water", 54}, {"Internet", 198}, {"TV", 112}, {"Mobile Phone", 303}, {"Home Phone", 89}, {"Natural Gas", 80}, {"Sewerage", 41}},
        {{"Electric", 4}, {"Water", 5}, {"Internet", 6}, {"TV", 7}, {"Mobile Phone", 8}, {"Home Phone", 9}, {"Natural Gas", 0}, {"Sewerage", 1}},
        0.0
    },
    {
        26, "Zane Doyle", "zane.doyle@example.com", "26 Mulberry Bend",
        {{"Electric", 95}, {"Water", 40}, {"Internet", 170}, {"TV", 90}, {"Mobile Phone", 260}, {"Home Phone", 70}, {"Natural Gas", 71}, {"Sewerage", 34}},
        {{"Electric", 5}, {"Water", 6}, {"Internet", 7}, {"TV", 8}, {"Mobile Phone", 9}, {"Home Phone", 0}, {"Natural Gas", 1}, {"Sewerage", 2}},
        0.0
    },
    {
        27, "Aisha Blake", "aisha.blake@example.com", "27 Rosewood Rd",
        {{"Electric", 101}, {"Water", 43}, {"Internet", 190}, {"TV", 108}, {"Mobile Phone", 276}, {"Home Phone", 80}, {"Natural Gas", 74}, {"Sewerage", 38}},
        {{"Electric", 6}, {"Water", 7}, {"Internet", 8}, {"TV", 9}, {"Mobile Phone", 0}, {"Home Phone", 1}, {"Natural Gas", 2}, {"Sewerage", 3}},
        0.0
    },
    {
        28, "Brandon Fields", "brandon.fields@example.com", "28 Walnut Circle",
        {{"Electric", 86}, {"Water", 35}, {"Internet", 155}, {"TV", 92}, {"Mobile Phone", 250}, {"Home Phone", 66}, {"Natural Gas", 66}, {"Sewerage", 29}},
        {{"Electric", 7}, {"Water", 8}, {"Internet", 9}, {"TV", 0}, {"Mobile Phone", 1}, {"Home Phone", 2}, {"Natural Gas", 3}, {"Sewerage", 4}},
        0.0
    },
    {
        29, "Cara Mendez", "cara.mendez@example.com", "29 Sequoia Park",
        {{"Electric", 109}, {"Water", 51}, {"Internet", 180}, {"TV", 123}, {"Mobile Phone", 297}, {"Home Phone", 92}, {"Natural Gas", 78}, {"Sewerage", 40}},
        {{"Electric", 8}, {"Water", 9}, {"Internet", 0}, {"TV", 1}, {"Mobile Phone", 2}, {"Home Phone", 3}, {"Natural Gas", 4}, {"Sewerage", 5}},
        0.0
    },
    {
        30, "Devon Nash", "devon.nash@example.com", "30 Lakeview Drive",
        {{"Electric", 94}, {"Water", 39}, {"Internet", 168}, {"TV", 95}, {"Mobile Phone", 270}, {"Home Phone", 74}, {"Natural Gas", 72}, {"Sewerage", 33}},
        {{"Electric", 9}, {"Water", 0}, {"Internet", 1}, {"TV", 2}, {"Mobile Phone", 3}, {"Home Phone", 4}, {"Natural Gas", 5}, {"Sewerage", 6}},
        0.0
    },
    {
        31, "Erica Novak", "erica.novak@example.com", "31 Prairie Hill",
        {{"Electric", 102}, {"Water", 44}, {"Internet", 177}, {"TV", 101}, {"Mobile Phone", 285}, {"Home Phone", 83}, {"Natural Gas", 75}, {"Sewerage", 35}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        32, "Felix Romero", "felix.romero@example.com", "32 Beacon St",
        {{"Electric", 88}, {"Water", 36}, {"Internet", 165}, {"TV", 88}, {"Mobile Phone", 260}, {"Home Phone", 69}, {"Natural Gas", 68}, {"Sewerage", 31}},
        {{"Electric", 1}, {"Water", 2}, {"Internet", 3}, {"TV", 4}, {"Mobile Phone", 5}, {"Home Phone", 6}, {"Natural Gas", 7}, {"Sewerage", 8}},
        0.0
    },
    {
        33, "Gabriella Lane", "gabriella.lane@example.com", "33 Cottonwood Lane",
        {{"Electric", 97}, {"Water", 41}, {"Internet", 174}, {"TV", 99}, {"Mobile Phone", 275}, {"Home Phone", 78}, {"Natural Gas", 70}, {"Sewerage", 34}},
        {{"Electric", 2}, {"Water", 3}, {"Internet", 4}, {"TV", 5}, {"Mobile Phone", 6}, {"Home Phone", 7}, {"Natural Gas", 8}, {"Sewerage", 9}},
        0.0
    },
    {
        34, "Hassan Malik", "hassan.malik@example.com", "34 Meadow Crescent",
        {{"Electric", 89}, {"Water", 33}, {"Internet", 160}, {"TV", 91}, {"Mobile Phone", 245}, {"Home Phone", 61}, {"Natural Gas", 65}, {"Sewerage", 28}},
        {{"Electric", 3}, {"Water", 4}, {"Internet", 5}, {"TV", 6}, {"Mobile Phone", 7}, {"Home Phone", 8}, {"Natural Gas", 9}, {"Sewerage", 0}},
        0.0
    },
    {
        35, "Ivy Thompson", "ivy.thompson@example.com", "35 Sage Row",
        {{"Electric", 111}, {"Water", 50}, {"Internet", 188}, {"TV", 116}, {"Mobile Phone", 310}, {"Home Phone", 86}, {"Natural Gas", 77}, {"Sewerage", 42}},
        {{"Electric", 4}, {"Water", 5}, {"Internet", 6}, {"TV", 7}, {"Mobile Phone", 8}, {"Home Phone", 9}, {"Natural Gas", 0}, {"Sewerage", 1}},
        0.0
    },
    {
        36, "Jorge Delgado", "jorge.delgado@example.com", "36 Redwood Terrace",
        {{"Electric", 93}, {"Water", 38}, {"Internet", 173}, {"TV", 96}, {"Mobile Phone", 268}, {"Home Phone", 76}, {"Natural Gas", 72}, {"Sewerage", 36}},
        {{"Electric", 5}, {"Water", 6}, {"Internet", 7}, {"TV", 8}, {"Mobile Phone", 9}, {"Home Phone", 0}, {"Natural Gas", 1}, {"Sewerage", 2}},
        0.0
    },
    {
        37, "Keira Walsh", "keira.walsh@example.com", "37 Ivy Grove",
        {{"Electric", 85}, {"Water", 31}, {"Internet", 148}, {"TV", 82}, {"Mobile Phone", 232}, {"Home Phone", 58}, {"Natural Gas", 63}, {"Sewerage", 26}},
        {{"Electric", 6}, {"Water", 7}, {"Internet", 8}, {"TV", 9}, {"Mobile Phone", 0}, {"Home Phone", 1}, {"Natural Gas", 2}, {"Sewerage", 3}},
        0.0
    },
    {
        38, "Liam O'Connor", "liam.oconnor@example.com", "38 Clover Lane",
        {{"Electric", 91}, {"Water", 36}, {"Internet", 158}, {"TV", 89}, {"Mobile Phone", 255}, {"Home Phone", 70}, {"Natural Gas", 68}, {"Sewerage", 30}},
        {{"Electric", 7}, {"Water", 8}, {"Internet", 9}, {"TV", 0}, {"Mobile Phone", 1}, {"Home Phone", 2}, {"Natural Gas", 3}, {"Sewerage", 4}},
        0.0
    },
    {
        39, "Mila Jensen", "mila.jensen@example.com", "39 Birch Bend",
        {{"Electric", 106}, {"Water", 48}, {"Internet", 192}, {"TV", 120}, {"Mobile Phone", 305}, {"Home Phone", 85}, {"Natural Gas", 79}, {"Sewerage", 41}},
        {{"Electric", 8}, {"Water", 9}, {"Internet", 0}, {"TV", 1}, {"Mobile Phone", 2}, {"Home Phone", 3}, {"Natural Gas", 4}, {"Sewerage", 5}},
        0.0
    },
    {
        40, "Noah Becker", "noah.becker@example.com", "40 Horizon Blvd",
        {{"Electric", 99}, {"Water", 43}, {"Internet", 172}, {"TV", 100}, {"Mobile Phone", 270}, {"Home Phone", 77}, {"Natural Gas", 71}, {"Sewerage", 35}},
        {{"Electric", 9}, {"Water", 0}, {"Internet", 1}, {"TV", 2}, {"Mobile Phone", 3}, {"Home Phone", 4}, {"Natural Gas", 5}, {"Sewerage", 6}},
        0.0
    },
    {
        41, "Olivia Russo", "olivia.russo@example.com", "41 Poplar Ridge",
        {{"Electric", 104}, {"Water", 46}, {"Internet", 180}, {"TV", 108}, {"Mobile Phone", 290}, {"Home Phone", 84}, {"Natural Gas", 75}, {"Sewerage", 38}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        42, "Peter Long", "peter.long@example.com", "42 Valley Brook",
        {{"Electric", 90}, {"Water", 39}, {"Internet", 160}, {"TV", 85}, {"Mobile Phone", 250}, {"Home Phone", 66}, {"Natural Gas", 69}, {"Sewerage", 30}},
        {{"Electric", 1}, {"Water", 2}, {"Internet", 3}, {"TV", 4}, {"Mobile Phone", 5}, {"Home Phone", 6}, {"Natural Gas", 7}, {"Sewerage", 8}},
        0.0
    },
    {
        43, "Quincy Tate", "quincy.tate@example.com", "43 Harbor Lane",
        {{"Electric", 99}, {"Water", 42}, {"Internet", 175}, {"TV", 97}, {"Mobile Phone", 272}, {"Home Phone", 76}, {"Natural Gas", 72}, {"Sewerage", 34}},
        {{"Electric", 2}, {"Water", 3}, {"Internet", 4}, {"TV", 5}, {"Mobile Phone", 6}, {"Home Phone", 7}, {"Natural Gas", 8}, {"Sewerage", 9}},
        0.0
    },
    {
        44, "Renee Dawson", "renee.dawson@example.com", "44 Crystal Pines",
        {{"Electric", 88}, {"Water", 35}, {"Internet", 150}, {"TV", 88}, {"Mobile Phone", 248}, {"Home Phone", 62}, {"Natural Gas", 66}, {"Sewerage", 28}},
        {{"Electric", 3}, {"Water", 4}, {"Internet", 5}, {"TV", 6}, {"Mobile Phone", 7}, {"Home Phone", 8}, {"Natural Gas", 9}, {"Sewerage", 0}},
        0.0
    },
    {
        45, "Santiago Lopez", "santiago.lopez@example.com", "45 Echo Glen",
        {{"Electric", 107}, {"Water", 48}, {"Internet", 185}, {"TV", 115}, {"Mobile Phone", 300}, {"Home Phone", 88}, {"Natural Gas", 77}, {"Sewerage", 39}},
        {{"Electric", 4}, {"Water", 5}, {"Internet", 6}, {"TV", 7}, {"Mobile Phone", 8}, {"Home Phone", 9}, {"Natural Gas", 0}, {"Sewerage", 1}},
        0.0
    },
    {
        46, "Talia Nguyen", "talia.nguyen@example.com", "46 Bluebell Court",
        {{"Electric", 94}, {"Water", 40}, {"Internet", 165}, {"TV", 93}, {"Mobile Phone", 265}, {"Home Phone", 73}, {"Natural Gas", 70}, {"Sewerage", 32}},
        {{"Electric", 5}, {"Water", 6}, {"Internet", 7}, {"TV", 8}, {"Mobile Phone", 9}, {"Home Phone", 0}, {"Natural Gas", 1}, {"Sewerage", 2}},
        0.0
    },
    {
        47, "Ulysses King", "ulysses.king@example.com", "47 Magnolia Walk",
        {{"Electric", 100}, {"Water", 45}, {"Internet", 178}, {"TV", 102}, {"Mobile Phone", 280}, {"Home Phone", 80}, {"Natural Gas", 74}, {"Sewerage", 36}},
        {{"Electric", 6}, {"Water", 7}, {"Internet", 8}, {"TV", 9}, {"Mobile Phone", 0}, {"Home Phone", 1}, {"Natural Gas", 2}, {"Sewerage", 3}},
        0.0
    },
    {
        48, "Valerie Chen", "valerie.chen@example.com", "48 Amberwood Ct",
        {{"Electric", 86}, {"Water", 34}, {"Internet", 155}, {"TV", 87}, {"Mobile Phone", 238}, {"Home Phone", 60}, {"Natural Gas", 65}, {"Sewerage", 29}},
        {{"Electric", 7}, {"Water", 8}, {"Internet", 9}, {"TV", 0}, {"Mobile Phone", 1}, {"Home Phone", 2}, {"Natural Gas", 3}, {"Sewerage", 4}},
        0.0
    },
    {
        49, "Wyatt Brooks", "wyatt.brooks@example.com", "49 Greenhill Rd",
        {{"Electric", 112}, {"Water", 52}, {"Internet", 195}, {"TV", 118}, {"Mobile Phone", 310}, {"Home Phone", 91}, {"Natural Gas", 80}, {"Sewerage", 41}},
        {{"Electric", 8}, {"Water", 9}, {"Internet", 0}, {"TV", 1}, {"Mobile Phone", 2}, {"Home Phone", 3}, {"Natural Gas", 4}, {"Sewerage", 5}},
        0.0
    },
    {
        50, "Xander Patel", "xander.patel@example.com", "50 Stoneview Dr",
        {{"Electric", 96}, {"Water", 38}, {"Internet", 170}, {"TV", 90}, {"Mobile Phone", 255}, {"Home Phone", 68}, {"Natural Gas", 69}, {"Sewerage", 33}},
        {{"Electric", 9}, {"Water", 0}, {"Internet", 1}, {"TV", 2}, {"Mobile Phone", 3}, {"Home Phone", 4}, {"Natural Gas", 5}, {"Sewerage", 6}},
        0.0
    },
    {
        51, "Yvette Silva", "yvette.silva@example.com", "51 Brookfield Ln",
        {{"Electric", 102}, {"Water", 44}, {"Internet", 182}, {"TV", 104}, {"Mobile Phone", 290}, {"Home Phone", 85}, {"Natural Gas", 76}, {"Sewerage", 37}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        52, "Zoe Armstrong", "zoe.armstrong@example.com", "52 Ironwood Dr",
        {{"Electric", 89}, {"Water", 36}, {"Internet", 158}, {"TV", 89}, {"Mobile Phone", 252}, {"Home Phone", 63}, {"Natural Gas", 68}, {"Sewerage", 31}},
        {{"Electric", 1}, {"Water", 2}, {"Internet", 3}, {"TV", 4}, {"Mobile Phone", 5}, {"Home Phone", 6}, {"Natural Gas", 7}, {"Sewerage", 8}},
        0.0
    },
    {
        53, "Ava Gillespie", "ava.gillespie@example.com", "53 Windmill Way",
        {{"Electric", 98}, {"Water", 41}, {"Internet", 174}, {"TV", 99}, {"Mobile Phone", 278}, {"Home Phone", 77}, {"Natural Gas", 72}, {"Sewerage", 34}},
        {{"Electric", 2}, {"Water", 3}, {"Internet", 4}, {"TV", 5}, {"Mobile Phone", 6}, {"Home Phone", 7}, {"Natural Gas", 8}, {"Sewerage", 9}},
        0.0
    },
    {
        54, "Blake Santana", "blake.santana@example.com", "54 Thistle Cove",
        {{"Electric", 87}, {"Water", 33}, {"Internet", 149}, {"TV", 82}, {"Mobile Phone", 239}, {"Home Phone", 58}, {"Natural Gas", 64}, {"Sewerage", 27}},
        {{"Electric", 3}, {"Water", 4}, {"Internet", 5}, {"TV", 6}, {"Mobile Phone", 7}, {"Home Phone", 8}, {"Natural Gas", 9}, {"Sewerage", 0}},
        0.0
    },
    {
        55, "Carmen Doyle", "carmen.doyle@example.com", "55 Foxglove Way",
        {{"Electric", 110}, {"Water", 51}, {"Internet", 190}, {"TV", 115}, {"Mobile Phone", 305}, {"Home Phone", 90}, {"Natural Gas", 78}, {"Sewerage", 40}},
        {{"Electric", 4}, {"Water", 5}, {"Internet", 6}, {"TV", 7}, {"Mobile Phone", 8}, {"Home Phone", 9}, {"Natural Gas", 0}, {"Sewerage", 1}},
        0.0
    },
    {
        56, "Derek O'Brien", "derek.obrien@example.com", "56 Raven Rock",
        {{"Electric", 92}, {"Water", 39}, {"Internet", 163}, {"TV", 91}, {"Mobile Phone", 260}, {"Home Phone", 71}, {"Natural Gas", 70}, {"Sewerage", 32}},
        {{"Electric", 5}, {"Water", 6}, {"Internet", 7}, {"TV", 8}, {"Mobile Phone", 9}, {"Home Phone", 0}, {"Natural Gas", 1}, {"Sewerage", 2}},
        0.0
    },
    {
        57, "Elena Reyes", "elena.reyes@example.com", "57 Winding Hollow",
        {{"Electric", 100}, {"Water", 45}, {"Internet", 180}, {"TV", 100}, {"Mobile Phone", 275}, {"Home Phone", 83}, {"Natural Gas", 74}, {"Sewerage", 36}},
        {{"Electric", 6}, {"Water", 7}, {"Internet", 8}, {"TV", 9}, {"Mobile Phone", 0}, {"Home Phone", 1}, {"Natural Gas", 2}, {"Sewerage", 3}},
        0.0
    },
    {
        58, "Freddie Adams", "freddie.adams@example.com", "58 Laurel Crest",
        {{"Electric", 85}, {"Water", 31}, {"Internet", 140}, {"TV", 80}, {"Mobile Phone", 235}, {"Home Phone", 55}, {"Natural Gas", 63}, {"Sewerage", 25}},
        {{"Electric", 7}, {"Water", 8}, {"Internet", 9}, {"TV", 0}, {"Mobile Phone", 1}, {"Home Phone", 2}, {"Natural Gas", 3}, {"Sewerage", 4}},
        0.0
    },
    {
        59, "Georgia Wolfe", "georgia.wolfe@example.com", "59 Pine Bluff",
        {{"Electric", 106}, {"Water", 49}, {"Internet", 192}, {"TV", 117}, {"Mobile Phone", 308}, {"Home Phone", 89}, {"Natural Gas", 79}, {"Sewerage", 42}},
        {{"Electric", 8}, {"Water", 9}, {"Internet", 0}, {"TV", 1}, {"Mobile Phone", 2}, {"Home Phone", 3}, {"Natural Gas", 4}, {"Sewerage", 5}},
        0.0
    },
    {
        60, "Harper Lin", "harper.lin@example.com", "60 Sunbeam Trail",
        {{"Electric", 97}, {"Water", 40}, {"Internet", 166}, {"TV", 92}, {"Mobile Phone", 260}, {"Home Phone", 72}, {"Natural Gas", 70}, {"Sewerage", 33}},
        {{"Electric", 9}, {"Water", 0}, {"Internet", 1}, {"TV", 2}, {"Mobile Phone", 3}, {"Home Phone", 4}, {"Natural Gas", 5}, {"Sewerage", 6}},
        0.0
    },
    {
        61, "Isaiah Foster", "isaiah.foster@example.com", "61 Riverbend Dr",
        {{"Electric", 104}, {"Water", 47}, {"Internet", 179}, {"TV", 109}, {"Mobile Phone", 288}, {"Home Phone", 83}, {"Natural Gas", 75}, {"Sewerage", 38}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        62, "Jasmine Burke", "jasmine.burke@example.com", "62 Woodland Hills",
        {{"Electric", 90}, {"Water", 38}, {"Internet", 157}, {"TV", 86}, {"Mobile Phone", 245}, {"Home Phone", 65}, {"Natural Gas", 67}, {"Sewerage", 29}},
        {{"Electric", 1}, {"Water", 2}, {"Internet", 3}, {"TV", 4}, {"Mobile Phone", 5}, {"Home Phone", 6}, {"Natural Gas", 7}, {"Sewerage", 8}},
        0.0
    },
    {
        63, "Kieran Webb", "kieran.webb@example.com", "63 Pebblebrook Ct",
        {{"Electric", 99}, {"Water", 43}, {"Internet", 176}, {"TV", 100}, {"Mobile Phone", 271}, {"Home Phone", 75}, {"Natural Gas", 72}, {"Sewerage", 34}},
        {{"Electric", 2}, {"Water", 3}, {"Internet", 4}, {"TV", 5}, {"Mobile Phone", 6}, {"Home Phone", 7}, {"Natural Gas", 8}, {"Sewerage", 9}},
        0.0
    },
    {
        64, "Lila Santana", "lila.santana@example.com", "64 Lakeforest Trail",
        {{"Electric", 88}, {"Water", 35}, {"Internet", 151}, {"TV", 87}, {"Mobile Phone", 247}, {"Home Phone", 61}, {"Natural Gas", 65}, {"Sewerage", 28}},
        {{"Electric", 3}, {"Water", 4}, {"Internet", 5}, {"TV", 6}, {"Mobile Phone", 7}, {"Home Phone", 8}, {"Natural Gas", 9}, {"Sewerage", 0}},
        0.0
    },
    {
        65, "Malik Grant", "malik.grant@example.com", "65 Rosefield Crescent",
        {{"Electric", 108}, {"Water", 50}, {"Internet", 188}, {"TV", 113}, {"Mobile Phone", 302}, {"Home Phone", 88}, {"Natural Gas", 79}, {"Sewerage", 41}},
        {{"Electric", 4}, {"Water", 5}, {"Internet", 6}, {"TV", 7}, {"Mobile Phone", 8}, {"Home Phone", 9}, {"Natural Gas", 0}, {"Sewerage", 1}},
        0.0
    },
    {
        66, "Nina McCarthy", "nina.mccarthy@example.com", "66 Crimson Leaf Ln",
        {{"Electric", 94}, {"Water", 39}, {"Internet", 164}, {"TV", 92}, {"Mobile Phone", 263}, {"Home Phone", 72}, {"Natural Gas", 70}, {"Sewerage", 32}},
        {{"Electric", 5}, {"Water", 6}, {"Internet", 7}, {"TV", 8}, {"Mobile Phone", 9}, {"Home Phone", 0}, {"Natural Gas", 1}, {"Sewerage", 2}},
        0.0
    },
    {
        67, "Oscar Meyer", "oscar.meyer@example.com", "67 Whispering Pines",
        {{"Electric", 101}, {"Water", 44}, {"Internet", 181}, {"TV", 103}, {"Mobile Phone", 284}, {"Home Phone", 81}, {"Natural Gas", 74}, {"Sewerage", 36}},
        {{"Electric", 6}, {"Water", 7}, {"Internet", 8}, {"TV", 9}, {"Mobile Phone", 0}, {"Home Phone", 1}, {"Natural Gas", 2}, {"Sewerage", 3}},
        0.0
    },
    {
        68, "Penelope Lane", "penelope.lane@example.com", "68 Ivy Court",
        {{"Electric", 85}, {"Water", 32}, {"Internet", 142}, {"TV", 81}, {"Mobile Phone", 234}, {"Home Phone", 54}, {"Natural Gas", 62}, {"Sewerage", 24}},
        {{"Electric", 7}, {"Water", 8}, {"Internet", 9}, {"TV", 0}, {"Mobile Phone", 1}, {"Home Phone", 2}, {"Natural Gas", 3}, {"Sewerage", 4}},
        0.0
    },
    {
        69, "Quinn Abbott", "quinn.abbott@example.com", "69 Cedar Bluff Rd",
        {{"Electric", 110}, {"Water", 53}, {"Internet", 194}, {"TV", 116}, {"Mobile Phone", 309}, {"Home Phone", 90}, {"Natural Gas", 80}, {"Sewerage", 42}},
        {{"Electric", 8}, {"Water", 9}, {"Internet", 0}, {"TV", 1}, {"Mobile Phone", 2}, {"Home Phone", 3}, {"Natural Gas", 4}, {"Sewerage", 5}},
        0.0
    },
    {
        70, "Riley Dalton", "riley.dalton@example.com", "70 Pinecone Trail",
        {{"Electric", 95}, {"Water", 37}, {"Internet", 167}, {"TV", 91}, {"Mobile Phone", 258}, {"Home Phone", 69}, {"Natural Gas", 70}, {"Sewerage", 33}},
        {{"Electric", 9}, {"Water", 0}, {"Internet", 1}, {"TV", 2}, {"Mobile Phone", 3}, {"Home Phone", 4}, {"Natural Gas", 5}, {"Sewerage", 6}},
        0.0
    },
    {
        71, "Sadie Emerson", "sadie.emerson@example.com", "71 Meadowbend Cir",
        {{"Electric", 103}, {"Water", 46}, {"Internet", 178}, {"TV", 106}, {"Mobile Phone", 288}, {"Home Phone", 86}, {"Natural Gas", 75}, {"Sewerage", 37}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        72, "Tobias Wells", "tobias.wells@example.com", "72 Birch Hollow",
        {{"Electric", 89}, {"Water", 36}, {"Internet", 155}, {"TV", 88}, {"Mobile Phone", 251}, {"Home Phone", 64}, {"Natural Gas", 68}, {"Sewerage", 30}},
        {{"Electric", 1}, {"Water", 2}, {"Internet", 3}, {"TV", 4}, {"Mobile Phone", 5}, {"Home Phone", 6}, {"Natural Gas", 7}, {"Sewerage", 8}},
        0.0
    },
    {
        73, "Uriah Ray", "uriah.ray@example.com", "73 Forestwalk Dr",
        {{"Electric", 98}, {"Water", 42}, {"Internet", 173}, {"TV", 99}, {"Mobile Phone", 276}, {"Home Phone", 76}, {"Natural Gas", 73}, {"Sewerage", 35}},
        {{"Electric", 2}, {"Water", 3}, {"Internet", 4}, {"TV", 5}, {"Mobile Phone", 6}, {"Home Phone", 7}, {"Natural Gas", 8}, {"Sewerage", 9}},
        0.0
    },
    {
        74, "Violet Romero", "violet.romero@example.com", "74 Wildflower Ct",
        {{"Electric", 86}, {"Water", 34}, {"Internet", 153}, {"TV", 86}, {"Mobile Phone", 243}, {"Home Phone", 59}, {"Natural Gas", 65}, {"Sewerage", 27}},
        {{"Electric", 3}, {"Water", 4}, {"Internet", 5}, {"TV", 6}, {"Mobile Phone", 7}, {"Home Phone", 8}, {"Natural Gas", 9}, {"Sewerage", 0}},
        0.0
    },
    {
        75, "Walter Singh", "walter.singh@example.com", "75 Elmshade Way",
        {{"Electric", 111}, {"Water", 51}, {"Internet", 191}, {"TV", 114}, {"Mobile Phone", 306}, {"Home Phone", 87}, {"Natural Gas", 78}, {"Sewerage", 40}},
        {{"Electric", 4}, {"Water", 5}, {"Internet", 6}, {"TV", 7}, {"Mobile Phone", 8}, {"Home Phone", 9}, {"Natural Gas", 0}, {"Sewerage", 1}},
        0.0
    },
    {
        76, "Ximena Black", "ximena.black@example.com", "76 Heatherstone Ln",
        {{"Electric", 93}, {"Water", 39}, {"Internet", 165}, {"TV", 90}, {"Mobile Phone", 261}, {"Home Phone", 70}, {"Natural Gas", 71}, {"Sewerage", 32}},
        {{"Electric", 5}, {"Water", 6}, {"Internet", 7}, {"TV", 8}, {"Mobile Phone", 9}, {"Home Phone", 0}, {"Natural Gas", 1}, {"Sewerage", 2}},
        0.0
    },
    {
        77, "Yusuf Delgado", "yusuf.delgado@example.com", "77 Stonemill Blvd",
        {{"Electric", 100}, {"Water", 44}, {"Internet", 180}, {"TV", 101}, {"Mobile Phone", 282}, {"Home Phone", 82}, {"Natural Gas", 74}, {"Sewerage", 36}},
        {{"Electric", 6}, {"Water", 7}, {"Internet", 8}, {"TV", 9}, {"Mobile Phone", 0}, {"Home Phone", 1}, {"Natural Gas", 2}, {"Sewerage", 3}},
        0.0
    },
    {
        78, "Zara Moreno", "zara.moreno@example.com", "78 Timber Hill Rd",
        {{"Electric", 84}, {"Water", 30}, {"Internet", 140}, {"TV", 78}, {"Mobile Phone", 232}, {"Home Phone", 52}, {"Natural Gas", 61}, {"Sewerage", 23}},
        {{"Electric", 7}, {"Water", 8}, {"Internet", 9}, {"TV", 0}, {"Mobile Phone", 1}, {"Home Phone", 2}, {"Natural Gas", 3}, {"Sewerage", 4}},
        0.0
    },
    {
        79, "Aiden Bishop", "aiden.bishop@example.com", "79 Cloverdale Ct",
        {{"Electric", 107}, {"Water", 49}, {"Internet", 189}, {"TV", 112}, {"Mobile Phone", 300}, {"Home Phone", 89}, {"Natural Gas", 76}, {"Sewerage", 39}},
        {{"Electric", 8}, {"Water", 9}, {"Internet", 0}, {"TV", 1}, {"Mobile Phone", 2}, {"Home Phone", 3}, {"Natural Gas", 4}, {"Sewerage", 5}},
        0.0
    },
    {
        80, "Brielle Faulkner", "brielle.faulkner@example.com", "80 Willow Trace",
        {{"Electric", 96}, {"Water", 40}, {"Internet", 169}, {"TV", 93}, {"Mobile Phone", 265}, {"Home Phone", 71}, {"Natural Gas", 70}, {"Sewerage", 33}},
        {{"Electric", 9}, {"Water", 0}, {"Internet", 1}, {"TV", 2}, {"Mobile Phone", 3}, {"Home Phone", 4}, {"Natural Gas", 5}, {"Sewerage", 6}},
        0.0
    },
    {
        81, "Caleb Holt", "caleb.holt@example.com", "81 Crescent Ridge",
        {{"Electric", 103}, {"Water", 46}, {"Internet", 178}, {"TV", 107}, {"Mobile Phone", 286}, {"Home Phone", 85}, {"Natural Gas", 75}, {"Sewerage", 37}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        82, "Daisy Vance", "daisy.vance@example.com", "82 Highland Ridge",
        {{"Electric", 91}, {"Water", 37}, {"Internet", 158}, {"TV", 85}, {"Mobile Phone", 246}, {"Home Phone", 66}, {"Natural Gas", 67}, {"Sewerage", 29}},
        {{"Electric", 1}, {"Water", 2}, {"Internet", 3}, {"TV", 4}, {"Mobile Phone", 5}, {"Home Phone", 6}, {"Natural Gas", 7}, {"Sewerage", 8}},
        0.0
    },
    {
        83, "Eli Navarro", "eli.navarro@example.com", "83 Hillside Way",
        {{"Electric", 99}, {"Water", 43}, {"Internet", 176}, {"TV", 99}, {"Mobile Phone", 270}, {"Home Phone", 75}, {"Natural Gas", 72}, {"Sewerage", 34}},
        {{"Electric", 2}, {"Water", 3}, {"Internet", 4}, {"TV", 5}, {"Mobile Phone", 6}, {"Home Phone", 7}, {"Natural Gas", 8}, {"Sewerage", 9}},
        0.0
    },
    {
        84, "Fiona Harper", "fiona.harper@example.com", "84 Whispering Hollow",
        {{"Electric", 88}, {"Water", 34}, {"Internet", 150}, {"TV", 87}, {"Mobile Phone", 244}, {"Home Phone", 60}, {"Natural Gas", 66}, {"Sewerage", 27}},
        {{"Electric", 3}, {"Water", 4}, {"Internet", 5}, {"TV", 6}, {"Mobile Phone", 7}, {"Home Phone", 8}, {"Natural Gas", 9}, {"Sewerage", 0}},
        0.0
    },
    {
        85, "Gavin Wells", "gavin.wells@example.com", "85 Golden Ridge",
        {{"Electric", 108}, {"Water", 50}, {"Internet", 187}, {"TV", 111}, {"Mobile Phone", 301}, {"Home Phone", 88}, {"Natural Gas", 78}, {"Sewerage", 40}},
        {{"Electric", 4}, {"Water", 5}, {"Internet", 6}, {"TV", 7}, {"Mobile Phone", 8}, {"Home Phone", 9}, {"Natural Gas", 0}, {"Sewerage", 1}},
        0.0
    },
    {
        86, "Hailey Brennan", "hailey.brennan@example.com", "86 Sycamore Grove",
        {{"Electric", 94}, {"Water", 39}, {"Internet", 164}, {"TV", 92}, {"Mobile Phone", 264}, {"Home Phone", 72}, {"Natural Gas", 70}, {"Sewerage", 32}},
        {{"Electric", 5}, {"Water", 6}, {"Internet", 7}, {"TV", 8}, {"Mobile Phone", 9}, {"Home Phone", 0}, {"Natural Gas", 1}, {"Sewerage", 2}},
        0.0
    },
    {
        87, "Ian Rhodes", "ian.rhodes@example.com", "87 Winding Lake Ct",
        {{"Electric", 101}, {"Water", 44}, {"Internet", 180}, {"TV", 102}, {"Mobile Phone", 283}, {"Home Phone", 80}, {"Natural Gas", 74}, {"Sewerage", 36}},
        {{"Electric", 6}, {"Water", 7}, {"Internet", 8}, {"TV", 9}, {"Mobile Phone", 0}, {"Home Phone", 1}, {"Natural Gas", 2}, {"Sewerage", 3}},
        0.0
    },
    {
        88, "Jocelyn Barrett", "jocelyn.barrett@example.com", "88 Aspen Meadow",
        {{"Electric", 85}, {"Water", 31}, {"Internet", 141}, {"TV", 80}, {"Mobile Phone", 232}, {"Home Phone", 53}, {"Natural Gas", 62}, {"Sewerage", 24}},
        {{"Electric", 7}, {"Water", 8}, {"Internet", 9}, {"TV", 0}, {"Mobile Phone", 1}, {"Home Phone", 2}, {"Natural Gas", 3}, {"Sewerage", 4}},
        0.0
    },
    {
        89, "Kylie Nash", "kylie.nash@example.com", "89 Spring Hollow",
        {{"Electric", 110}, {"Water", 52}, {"Internet", 193}, {"TV", 115}, {"Mobile Phone", 308}, {"Home Phone", 90}, {"Natural Gas", 79}, {"Sewerage", 41}},
        {{"Electric", 8}, {"Water", 9}, {"Internet", 0}, {"TV", 1}, {"Mobile Phone", 2}, {"Home Phone", 3}, {"Natural Gas", 4}, {"Sewerage", 5}},
        0.0
    },
    {
        90, "Luca Bowman", "luca.bowman@example.com", "90 Cedar Heights",
        {{"Electric", 96}, {"Water", 40}, {"Internet", 167}, {"TV", 92}, {"Mobile Phone", 260}, {"Home Phone", 71}, {"Natural Gas", 70}, {"Sewerage", 33}},
        {{"Electric", 9}, {"Water", 0}, {"Internet", 1}, {"TV", 2}, {"Mobile Phone", 3}, {"Home Phone", 4}, {"Natural Gas", 5}, {"Sewerage", 6}},
        0.0
    },
    {
        91, "Mara Kim", "mara.kim@example.com", "91 Willowbrook Pl",
        {{"Electric", 102}, {"Water", 45}, {"Internet", 179}, {"TV", 105}, {"Mobile Phone", 287}, {"Home Phone", 84}, {"Natural Gas", 75}, {"Sewerage", 37}},
        {{"Electric", 0}, {"Water", 1}, {"Internet", 2}, {"TV", 3}, {"Mobile Phone", 4}, {"Home Phone", 5}, {"Natural Gas", 6}, {"Sewerage", 7}},
        0.0
    },
    {
        92, "Noelle Tran", "noelle.tran@example.com", "92 Fern Grove",
        {{"Electric", 89}, {"Water", 36}, {"Internet", 156}, {"TV", 86}, {"Mobile Phone", 250}, {"Home Phone", 64}, {"Natural Gas", 68}, {"Sewerage", 30}},
        {{"Electric", 1}, {"Water", 2}, {"Internet", 3}, {"TV", 4}, {"Mobile Phone", 5}, {"Home Phone", 6}, {"Natural Gas", 7}, {"Sewerage", 8}},
        0.0
    },
    {
        93, "Orlando Diaz", "orlando.diaz@example.com", "93 Maple Trace",
        {{"Electric", 97}, {"Water", 41}, {"Internet", 172}, {"TV", 98}, {"Mobile Phone", 277}, {"Home Phone", 77}, {"Natural Gas", 73}, {"Sewerage", 35}},
        {{"Electric", 2}, {"Water", 3}, {"Internet", 4}, {"TV", 5}, {"Mobile Phone", 6}, {"Home Phone", 7}, {"Natural Gas", 8}, {"Sewerage", 9}},
        0.0
    },
    {
        94, "Piper Steele", "piper.steele@example.com", "94 Sage Valley",
        {{"Electric", 87}, {"Water", 33}, {"Internet", 152}, {"TV", 85}, {"Mobile Phone", 241}, {"Home Phone", 57}, {"Natural Gas", 64}, {"Sewerage", 26}},
        {{"Electric", 3}, {"Water", 4}, {"Internet", 5}, {"TV", 6}, {"Mobile Phone", 7}, {"Home Phone", 8}, {"Natural Gas", 9}, {"Sewerage", 0}},
        0.0
    },
    {
        95, "Quentin Vega", "quentin.vega@example.com", "95 Morninghill Ln",
        {{"Electric", 112}, {"Water", 54}, {"Internet", 196}, {"TV", 117}, {"Mobile Phone", 311}, {"Home Phone", 92}, {"Natural Gas", 81}, {"Sewerage", 43}},
        {{"Electric", 4}, {"Water", 5}, {"Internet", 6}, {"TV", 7}, {"Mobile Phone", 8}, {"Home Phone", 9}, {"Natural Gas", 0}, {"Sewerage", 1}},
        0.0
    },
    {
        96, "Ruby Ellis", "ruby.ellis@example.com", "96 Harborview Rd",
        {{"Electric", 93}, {"Water", 39}, {"Internet", 163}, {"TV", 91}, {"Mobile Phone", 262}, {"Home Phone", 73}, {"Natural Gas", 70}, {"Sewerage", 32}},
        {{"Electric", 5}, {"Water", 6}, {"Internet", 7}, {"TV", 8}, {"Mobile Phone", 9}, {"Home Phone", 0}, {"Natural Gas", 1}, {"Sewerage", 2}},
        0.0
    },
    {
        97, "Soren Burke", "soren.burke@example.com", "97 Sunset View",
        {{"Electric", 100}, {"Water", 44}, {"Internet", 182}, {"TV", 103}, {"Mobile Phone", 283}, {"Home Phone", 82}, {"Natural Gas", 74}, {"Sewerage", 36}},
        {{"Electric", 6}, {"Water", 7}, {"Internet", 8}, {"TV", 9}, {"Mobile Phone", 0}, {"Home Phone", 1}, {"Natural Gas", 2}, {"Sewerage", 3}},
        0.0
    },
    {
        98, "Tessa Monroe", "tessa.monroe@example.com", "98 Pine Hollow Pl",
        {{"Electric", 84}, {"Water", 30}, {"Internet", 139}, {"TV", 76}, {"Mobile Phone", 231}, {"Home Phone", 51}, {"Natural Gas", 60}, {"Sewerage", 22}},
        {{"Electric", 7}, {"Water", 8}, {"Internet", 9}, {"TV", 0}, {"Mobile Phone", 1}, {"Home Phone", 2}, {"Natural Gas", 3}, {"Sewerage", 4}},
        0.0
    },
    {
        99, "Tristan Mills", "tristan.mills@example.com", "99 Cliffside Terrace",
        {{"Electric", 106}, {"Water", 48}, {"Internet", 190}, {"TV", 111}, {"Mobile Phone", 299}, {"Home Phone", 87}, {"Natural Gas", 77}, {"Sewerage", 39}},
        {{"Electric", 8}, {"Water", 9}, {"Internet", 0}, {"TV", 1}, {"Mobile Phone", 2}, {"Home Phone", 3}, {"Natural Gas", 4}, {"Sewerage", 5}},
        0.0
    },
    {
        100, "Zayden Pierce", "zayden.pierce@example.com", "100 Summit Crest Blvd",
        {{"Electric", 99}, {"Water", 42}, {"Internet", 175}, {"TV", 95}, {"Mobile Phone", 270}, {"Home Phone", 78}, {"Natural Gas", 72}, {"Sewerage", 34}},
        {{"Electric", 9}, {"Water", 0}, {"Internet", 1}, {"TV", 2}, {"Mobile Phone", 3}, {"Home Phone", 4}, {"Natural Gas", 5}, {"Sewerage", 6}},
        0.0
    }    
};
