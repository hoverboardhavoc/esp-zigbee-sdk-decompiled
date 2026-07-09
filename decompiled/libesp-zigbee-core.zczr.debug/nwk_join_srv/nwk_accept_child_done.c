/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_accept_child_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_accept_child_done(int param_1,undefined4 param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar2 = nwk_neighbor_table_get_by_extended(param_2);
  if (iVar2 == 0) {
    return;
  }
  if (-1 < *(int *)(iVar2 + 0xc) << 0x14) {
    return;
  }
  if (param_1 != 0) {
    nwk_neighbor_table_delete();
    return;
  }
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffff7ff;
  if (param_3 < 5) {
    if ((param_3 < 3) && (1 < param_3)) {
      if (param_3 != 2) goto _L0;
_L0:
      nwk_neighbor_set_auth(iVar2);
      goto _L0;
    }
  }
  else {
    if (param_3 == 5) goto _L0;
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0xdc,
                  "nwk_accept_child_done",&_L0);
  }
  nwk_neighbor_set_unauth(iVar2,10);
_L0:
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  local_20._0_2_ = CONCAT11((char)param_3,(char)(*(uint *)(iVar2 + 0xc) >> 0xd)) & 0xff1f;
  local_20 = (uint)(ushort)local_20;
  uVar1 = nwk_neighbor_get_shortaddr(iVar2);
  local_20 = CONCAT22(uVar1,(ushort)local_20);
  nwk_neighbor_get_extaddr(iVar2,&uStack_1c);
  nwk_join_indication(&local_20);
  return;
}

