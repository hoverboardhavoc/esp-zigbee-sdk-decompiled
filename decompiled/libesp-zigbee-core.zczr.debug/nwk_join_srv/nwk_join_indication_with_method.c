/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_join_indication_with_method
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_join_indication_with_method(int param_1,undefined1 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_a1;
  char *pcVar4;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 != 0) {
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    local_20._0_2_ = CONCAT11(param_2,(char)(*(uint *)(param_1 + 0xc) >> 0xd)) & 0xff1f;
    local_20 = (uint)(ushort)local_20;
    uVar1 = nwk_neighbor_get_shortaddr();
    local_20 = CONCAT22(uVar1,(ushort)local_20);
    nwk_neighbor_get_extaddr(param_1,&uStack_1c);
    nwk_join_indication(&local_20);
    return;
  }
  pcVar4 = "nwk_join_indication_with_method";
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0xc3,
                        "joiner != ((void *)0)");
  iVar3 = nwk_neighbor_table_get_by_extended(extraout_a1);
  if (iVar3 == 0) {
    return;
  }
  if (-1 < *(int *)(iVar3 + 0xc) << 0x14) {
    return;
  }
  if (iVar2 != 0) {
    nwk_neighbor_table_delete();
    return;
  }
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xfffff7ff;
  if (pcVar4 < (char *)0x5) {
    if ((pcVar4 < (char *)0x3) && ((char *)0x1 < pcVar4)) {
      if (pcVar4 != (char *)0x2) goto _L0;
_L0:
      nwk_neighbor_set_auth(iVar3);
      goto _L0;
    }
  }
  else {
    if (pcVar4 == (char *)0x5) goto _L0;
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0xe8,
                  "nwk_accept_child_done",&_L0);
  }
  nwk_neighbor_set_unauth(iVar3,10);
_L0:
  nwk_join_indication_with_method(iVar3,pcVar4);
  return;
}

