/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_handle_mlme_asso_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_mlme_asso_confirm(uint param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  if ((*(byte *)(*(int *)(iVar1 + 0xac4) + 0x13) & 0x1f) == param_1) {
    uVar2 = (uint)*(byte *)(param_2 + 1);
    if (uVar2 == 0) {
      uVar2 = 0;
      goto _L0;
    }
  }
  else {
    uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x1c8,
                          "nwk_handle_mlme_asso_confirm",
                          "iface_id == (((*core_globals_get()).nwk).ctx).parent_candidate->mac_iface_idx"
                         );
  }
  uVar2 = uVar2 | 0x100;
_L0:
  nwk_do_attach_done(uVar2,*param_2);
  return;
}

