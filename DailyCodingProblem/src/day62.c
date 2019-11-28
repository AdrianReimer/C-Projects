//
// Created by adrianreimer on 11/28/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Palantir.

    In academia, the h-index is a metric used to calculate the impact of a researcher's papers.
    It is calculated as follows:

    A researcher has index h if at least h of her N papers have h citations each.
    If there are multiple h satisfying this formula, the maximum is chosen.

    For example, suppose N = 5, and the respective citations of each paper are [4, 3, 0, 1, 5].
    Then the h-index would be 3, since the researcher has 3 papers with at least 3 citations.

    Given a list of paper citations of a researcher, calculate their h-index.
 */
#include <stdlib.h>
#include "day62.h"

#define SPLIT_PROFIT 100


size_t
hIndex(size_t citListLen, int citList[citListLen])
{
    int hIdx = 0;
    int paperCnt = 0;
    int i = 0;
    int mid = citListLen / 2;

    if(citListLen > SPLIT_PROFIT) {
        while (i < (citListLen / SPLIT_PROFIT)) {
            paperCnt = 0;
            for (size_t i = 0; i < citListLen; i++) {
                if (citList[i] >= mid) {
                    paperCnt++;
                }
            }
            if (paperCnt >= mid) {
                if (mid > hIdx) {
                    hIdx = mid;
                }
                mid += mid / 2;
            } else {
                mid -= mid / 2;
            }
            i++;
        }
    }

    do {
        paperCnt = 0;
        hIdx++;
        for (size_t i = 0; i < citListLen; i++) {
            if (citList[i] >= hIdx) {
                paperCnt++;
            }
        }
    } while(paperCnt >= hIdx);
    return --hIdx;
}
