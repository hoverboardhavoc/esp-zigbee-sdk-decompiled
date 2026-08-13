/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_accept_child_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_accept_child_done(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = nwk_neighbor_table_get_by_extended(param_2);
  if (iVar1 == 0) {
    return;
  }
  if (-1 < *(int *)(iVar1 + 0xc) << 0x14) {
    return;
  }
  if (param_1 != 0) {
    nwk_neighbor_table_delete();
    return;
  }
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffff7ff;
  if (param_3 < 5) {
    if ((param_3 < 3) && (1 < param_3)) {
      if (param_3 != 2) goto _L0;
_L0:
      nwk_neighbor_set_auth(iVar1);
      goto _L0;
    }
  }
  else {
    if (param_3 == 5) goto _L0;
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0xe8,
                  "nwk_accept_child_done",&_L0);
  }
  nwk_neighbor_set_unauth(iVar1,10);
_L0:
  nwk_join_indication_with_method(iVar1,param_3);
  return;
}

