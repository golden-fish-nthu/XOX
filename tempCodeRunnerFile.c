        } else if (!strcmp(buf, "erase2")) {
            scanf("%s", buf);
            erase2(&head, buf); // erase2 <color>
        } else if (!strcmp(buf, "reverse")) {
            scanf("%d%d", &num1, &num2);
            reverse(&head, num1, num2); // reverse <dest1> <dest2>