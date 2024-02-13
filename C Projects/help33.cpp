static void force_fpf()
          {
              float x, *y; /* Just declares two variables */
              y = &x;      /* Forces linkage of FP formats */
              x = *y;      /* Suppress warning message about x */
          }