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
|  H_00       |One Pair |1 pair of any rank and 3 any other|1|1|Scenario based|

## Table no: Low level test plan

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |--------------------------------------------------------------|  ------------|-------------|----------------|Requirement based |
|  L_02       |--------------------------------------------------------------|  ------------|-------------|----------------|Scenario based    |
|  L_03       |--------------------------------------------------------------|  ------------|-------------|----------------|Boundary based    |