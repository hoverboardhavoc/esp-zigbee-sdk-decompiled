/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_join_ed.o -> touchlink_join_ed_req_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_join_ed_req_confirm(touchlink_cmd_cnf_t *cnf,void *arg)

{
  uint8_t uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *extraout_a1;
  
  if (cnf != (touchlink_cmd_cnf_t *)0x0) {
    iVar3 = touchlink_transaction_get();
    *(undefined1 *)(iVar3 + 0x60c) = 10;
    uVar1 = cnf->status;
    iVar3 = touchlink_transaction_get();
    uVar2 = touchlink_convert_status(uVar1);
    *(undefined1 *)(iVar3 + 0x610) = uVar2;
    iVar3 = touchlink_transaction_get();
    *(undefined2 *)(iVar3 + 0x612) = 5000;
    iVar3 = touchlink_transaction_get();
    *(void **)(iVar3 + 0x614) = arg;
    iVar3 = touchlink_transaction_get();
    touchlink_schedule_transaction_event(iVar3 + 0x60c);
    return;
  }
  puVar4 = (undefined1 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_join_ed.c",
                         0x12,"touchlink_join_ed_req_confirm",0x10000);
  if (puVar4 == (undefined1 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_join_ed.c",0x3c,
                  "touchlink_join_ed_rsp_confirm",0x10000);
  }
  else {
    iVar3 = touchlink_transaction_get();
    *(undefined1 *)(iVar3 + 0x60c) = 9;
    iVar3 = touchlink_transaction_get();
    if ((undefined1 *)(iVar3 + 0x610) != extraout_a1) {
      iVar3 = touchlink_transaction_get();
      *(undefined1 *)(iVar3 + 0x610) = 1;
      goto _L0;
    }
  }
  uVar2 = touchlink_convert_status(*puVar4);
  *extraout_a1 = uVar2;
_L0:
  iVar3 = touchlink_transaction_get();
  touchlink_schedule_transaction_event(iVar3 + 0x60c);
  return;
}

