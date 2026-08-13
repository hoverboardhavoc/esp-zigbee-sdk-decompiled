/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_delete_nbr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nbt_delete_nbr(undefined4 *param_1,short *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = ((int)param_2 - param_1[1] >> 2) * -0x49249249;
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(param_1 + 2)) {
    if (*param_2 != -1) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x10a,
                  "nbt_delete_nbr","idx < tbl->ent_nr");
_L0:
    nwk_address_unlock_ref();
  }
  iVar2 = test_and_clr_bitmap(uVar1 & 0xffff,*param_1);
  if (iVar2 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x10e,
                  "nbt_delete_nbr","test_and_clr_bitmap(idx, tbl->ent_in_use)");
  }
  else {
    iVar2 = param_1[1];
    uVar1 = nwk_neighbor_table_get_router_capacity();
    if ((((int)param_2 - iVar2 >> 2) * -0x49249249 & 0xffffU) < uVar1) goto _L0;
    if ((*(uint *)(param_2 + 6) & 3) == 2) {
      nwk_neighbor_table_remove_stored_child(param_2);
      nbt_dec_ed_cnt(param_1);
      return;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x110,
                "nbt_delete_nbr","nwk_device_type_is_zed(nbr->device_type)");
_L0:
  if (((*(uint *)(param_2 + 6) & 3) != 0) && ((*(uint *)(param_2 + 6) & 3) != 1)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x114,
                  "nbt_delete_nbr","nwk_device_type_is_zczr(nbr->device_type)");
  }
  nbt_dec_router_cnt(param_1);
  return;
}

