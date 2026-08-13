/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_store_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_table_store_child(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  uint uStack_14;
  
  if ((*(uint *)(param_1 + 0xc) & 0x3c3) == 0x42) {
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    nwk_neighbor_table_remove_stored_child();
    uVar1 = nwk_neighbor_get_shortaddr(param_1);
    uStack_24 = CONCAT22(uVar1,(undefined2)uStack_24);
    nwk_neighbor_get_extaddr(param_1,&uStack_20);
    uStack_14 = uStack_14 & 0xffffffe0 | (*(uint *)(param_1 + 0xc) >> 10 & 1) << 4 |
                *(uint *)(param_1 + 0x14) >> 0x14 & 0xf;
    uStack_18 = CONCAT22(CONCAT11(*(undefined1 *)(param_1 + 7),
                                  (char)(*(uint *)(param_1 + 0xc) >> 0xd)),
                         *(undefined2 *)(param_1 + 0x10)) & 0xff1fffff;
    ds_internal_add_entry(4,&uStack_24,0x14);
    return;
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x295,
                        "nwk_neighbor_table_store_child",
                        "(child->device_type == NWK_DEVICE_TYPE_ZED) && (child->relationship == NWK_RELATIONSHIP_CHILD)"
                       );
  uVar4 = *(uint *)(iVar2 + 0xc) & 3;
  if (uVar4 == 2) {
    iVar3 = 1;
  }
  else {
    iVar3 = 2;
  }
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffc3f | iVar3 << 6;
  if (uVar4 == 2) {
    iVar3 = core_globals_get();
    nwk_neighbor_zed_set_timeout(iVar2,*(undefined1 *)(iVar3 + 0xa29));
    nwk_neighbor_table_store_child(iVar2);
  }
  else {
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x19) = *(undefined1 *)(iVar3 + 0xa25);
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x18) = *(undefined1 *)(iVar3 + 0xa25);
  }
  return;
}

