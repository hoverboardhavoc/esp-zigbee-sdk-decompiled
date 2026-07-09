/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_asso_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_asso_indication(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = nwk_is_router_started();
  if (iVar1 != 0) {
    uStack_14 = 0xfffe;
    uStack_1c = *param_2;
    uStack_18 = param_2[1];
    iVar1 = nwk_accept_child(param_1,*(undefined1 *)(param_2 + 2),0,&uStack_14);
    uStack_14._0_3_ = CONCAT12((char)iVar1,(undefined2)uStack_14);
    if ((iVar1 != 0xe2) && (iVar1 = nwk_mm_asso_response(param_1,&uStack_1c), iVar1 != 0)) {
      nwk_accept_child_done(&uStack_1c,0);
    }
  }
  return;
}

