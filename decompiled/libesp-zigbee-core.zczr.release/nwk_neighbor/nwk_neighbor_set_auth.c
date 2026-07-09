/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_set_auth
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_set_auth(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  
  uVar3 = *(uint *)(param_1 + 0xc) & 0xfffffc3f;
  if ((*(uint *)(param_1 + 0xc) & 3) != 2) {
    *(uint *)(param_1 + 0xc) = uVar3 | 0x80;
    iVar2 = core_globals_get();
    *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(iVar2 + 0xa25);
    iVar2 = core_globals_get();
    *(undefined1 *)(param_1 + 0x18) = *(undefined1 *)(iVar2 + 0xa25);
    return;
  }
  *(uint *)(param_1 + 0xc) = uVar3 | 0x40;
  iVar2 = core_globals_get();
  nwk_neighbor_zed_set_timeout(param_1,*(undefined1 *)(iVar2 + 0xa29));
  if ((*(uint *)(param_1 + 0xc) & 0x3c3) != 0x42) {
    param_1 = __assert_func(0,0,0,0);
  }
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  nwk_neighbor_table_remove_stored_child();
  uVar1 = nwk_neighbor_get_shortaddr(param_1);
  uStack_24 = CONCAT22(uVar1,(undefined2)uStack_24);
  nwk_neighbor_get_extaddr(param_1,&uStack_20);
  uStack_14 = CONCAT31(uStack_14._1_3_,
                       (byte)(*(uint *)(param_1 + 0xc) >> 6) & 0x10 |
                       (byte)(*(uint *)(param_1 + 0x14) >> 0x14) & 0xf | (byte)uStack_14 & 0xe0);
  uStack_18 = CONCAT22(CONCAT11(*(undefined1 *)(param_1 + 7),(char)(*(uint *)(param_1 + 0xc) >> 0xd)
                               ),*(undefined2 *)(param_1 + 0x10)) & 0xff1fffff;
  ds_internal_add_entry(4,&uStack_24,0x14);
  return;
}

