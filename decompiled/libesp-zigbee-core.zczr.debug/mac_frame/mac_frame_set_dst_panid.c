/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_set_dst_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_frame_set_dst_panid(ezb_radio_frame_t *frame,ezb_panid_t panid)

{
  uint16_t *puVar1;
  uint8_t uVar2;
  undefined3 extraout_var;
  undefined4 *puVar3;
  undefined3 extraout_var_00;
  undefined2 *extraout_a1;
  
  puVar1 = (uint16_t *)frame->psdu;
  uVar2 = mac_fcf_find_dst_panid_index(*puVar1);
  if (CONCAT31(extraout_var,uVar2) == 0xff) {
    puVar3 = (undefined4 *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x153,
                           "mac_frame_set_dst_panid","index != 0xff");
    puVar1 = (uint16_t *)*puVar3;
    uVar2 = mac_fcf_find_src_panid_index(*puVar1);
    if (CONCAT31(extraout_var_00,uVar2) != 0xff) {
      *extraout_a1 = *(undefined2 *)((int)puVar1 + CONCAT31(extraout_var_00,uVar2));
    }
    return;
  }
  *(ezb_panid_t *)((int)puVar1 + CONCAT31(extraout_var,uVar2)) = panid;
  return;
}

