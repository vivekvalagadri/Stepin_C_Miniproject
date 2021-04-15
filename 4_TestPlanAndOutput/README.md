# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**   | **Exp I/P** | **Exp O/P** | **Actual Out** | **Type Of Test** | 
|-------------|-----------------  |-------------|-------------|----------------|------------------|
|  H_01       |RoyalFlush   |T,J,Q,K,A of same suit|1|1|Boundary based|
|  H_02       |Straight flush|5 cards in order of same suit|1|1|Scenario based|
|  H_03       |Four of a Kind |4 cards of same rank and any other card|1|1|Scenario based|
|  H_04       |Full House |3 cards of the same rank and a pair |1|1|Scenario based|
|  H_05       |Flush |5 cards of same suit|1|1|Scenario based|
|  H_06       |Straight |5 cards in order|1|1|Scenario based|
|  H_07       |Three of a Kind |3 cards of the same rank and 2 any other|1|1|Scenario based|
|  H_08       |Two Pair |2 pairs of any rank and 1 any other|1|1|Scenario based|
|  H_09       |One Pair |1 pair of any rank and 3 any other|1|1|Scenario based|

## Table no: Low level test plan

| **Test ID** | **Description**   | **Exp I/P** | **Exp O/P** | **Actual Out** | **Type Of Test** | 
|-------------|-----------------  |-------------|-------------|----------------|------------------|
|  L_01       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Boundary based|
|  L_02       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c2))|card c2[5]={{2,14},{1,10},{3,11},{2,13},{4,12}}|1|1|Boundary based|

|  L_11       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|
|  L_12       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|

|  L_21       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|
|  L_22       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|

|  L_31       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|
|  L_32       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|

|  L_41       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|
|  L_42       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|

|  L_51       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|
|  L_52       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|

|  L_61       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|
|  L_62       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|

|  L_71       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|
|  L_72       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|

|  L_81       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|
|  L_82       |TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1))|card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}}|1|1|Scenario based|