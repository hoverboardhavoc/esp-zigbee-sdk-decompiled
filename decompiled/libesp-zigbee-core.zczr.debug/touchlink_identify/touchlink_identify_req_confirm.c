/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_identify.o -> touchlink_identify_req_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_identify_req_confirm(touchlink_cmd_cnf_t *cnf,void *arg)

{
  undefined2 extraout_a0;
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  code *pcStack_28;
  char *pcStack_24;
  
  if (cnf == (touchlink_cmd_cnf_t *)0x0) {
    pcVar3 = "touchlink_identify_req_confirm";
    puVar2 = (undefined1 *)
             __assert_func("//build/esp-zigbee/src/core/touchlink/touchlink_identify.c",0x14,0x10000
                          );
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    pcStack_28 = (code *)0x0;
    pcStack_24 = (char *)0x0;
    if ((puVar2 != (undefined1 *)0x0) && (iVar1 = touchlink_transaction_id(0), iVar1 != 0)) {
      uStack_30 = touchlink_transaction_id(0);
      uStack_2c = CONCAT22(uStack_2c._2_2_,extraout_a0);
      pcStack_28 = touchlink_identify_req_confirm;
      uStack_3c = CONCAT31(uStack_3c._1_3_,3);
      uStack_38 = *(undefined4 *)(puVar2 + 2);
      uStack_3c = CONCAT13(puVar2[1],CONCAT12(*puVar2,(undefined2)uStack_3c));
      uStack_34 = CONCAT22(uStack_34._2_2_,*(undefined2 *)(puVar2 + 6));
      pcStack_24 = pcVar3;
      zcl_touchlink_identify_req(&uStack_3c);
    }
    return;
  }
  return;
}

