        int iShop = 0;
38	    int iRent = 0;
39	    int i = 0;
40	    ll sol = 0;
41	    while (i < n) { //n starts going down once better to rent cows rather than milk them. i goes up when sold cow's milk rather than rented them
42	        int litres = production[i]; // 7 gal
43	        int moneyT = 0, curI = iShop; // curI = 0
44	        int last = 0;
45	        while (curI < m) { // 0 < 3 --> 1 < 3
46	            int rest = min(litres, shops[curI].second); //rest = min(7 gal, 5 gal) i.e. min(cur cow milk vs milk shop wants to buy) --> rest = min(2 gal, 15 gal)
47	            moneyT += shops[curI].first * rest; // moneyT += 25 cents * 5 gal i.e. moneyTotal += cur cow milk * cur shop price OR cur shop milk * cur shop price --> moneyT = 15 * 2 gal
48	            litres -= rest; // litres (7gal) -= 5 gal i.e. litres = 2 gal --> litres = 0 gal
49	
50	            if (litres == 0) {
51	                last = rest; // last = 2 gal (2 gal/15 gal into 2nd milk buying shop)
52	                break;
53	            } else {
54	                curI++;
55	            }
56	        }
57	
58	        if (iRent >= r || moneyT > rent[iRent]) { // 0 >= 4 (if already rented out all cows) || 125 + 30 = 155 (money up to last cow) > 250 (best price you'd get for that cow)
59	            sol += moneyT;
60	            iShop = curI; // next shop to be considered will be shop stopped at above
61	            if (iShop < m) shops[iShop].second -= last; // if shop stopped at above is not final shop, subtract number of gals available to buy by shop by gals already bought above
62	            i++;
63	        } else {
64	            sol += rent[iRent];
65	            n--; // !!!! n-- rather than i++ because if your best milk producing cow is not beating the best rent price, then you'd still want to rent the least milk producing cow so that at the end, once you've rented all cows possible, if there are still cows available to profit from, you can sell the most milk for the most expensive price
66	            iRent++;
67	        }
68	    }

        cout << sol << '\n';



//LOGIC FOR EXAMPLE INPUTS AS FOLLOWS:
5 3 4 = n m r

7
6
4
2
1

25 5
15 15
10 2

250
100
80
40
69	