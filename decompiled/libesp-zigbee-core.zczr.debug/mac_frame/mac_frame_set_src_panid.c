/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_set_src_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_frame_set_src_panid(ezb_radio_frame_t *frame,ezb_panid_t panid)

{
  ushort fcf;
  uint16_t *puVar1;
  uint8_t uVar2;
  undefined3 extraout_var;
  undefined4 *puVar3;
  undefined3 extraout_var_00;
  int iVar4;
  undefined1 *extraout_a1;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort *puVar7;
  
  puVar1 = (uint16_t *)frame->psdu;
  uVar2 = mac_fcf_find_src_panid_index(*puVar1);
  if (CONCAT31(extraout_var,uVar2) != 0xff) {
    *(ezb_panid_t *)((int)puVar1 + CONCAT31(extraout_var,uVar2)) = panid;
    return;
  }
  puVar3 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x16e,
                         "mac_frame_set_src_panid","index != 0xff");
  puVar7 = (ushort *)*puVar3;
  fcf = *puVar7;
  uVar2 = mac_fcf_find_dstaddr_index(fcf);
  iVar4 = CONCAT31(extraout_var_00,uVar2);
  if ((fcf & 0xc00) != 0x800) {
    if ((fcf & 0xc00) != 0xc00) {
      if ((fcf & 0xc00) != 0) {
        *extraout_a1 = 0;
        return;
      }
      goto _L0;
    }
    if (iVar4 != 0xff) {
      *extraout_a1 = 3;
      uVar5 = *(undefined4 *)(iVar4 + (int)puVar7);
      uVar6 = ((undefined4 *)(iVar4 + (int)puVar7))[1];
      *(short *)(extraout_a1 + 2) = (short)uVar5;
      *(short *)(extraout_a1 + 4) = (short)((uint)uVar5 >> 0x10);
      *(short *)(extraout_a1 + 6) = (short)uVar6;
      *(short *)(extraout_a1 + 8) = (short)((uint)uVar6 >> 0x10);
      return;
    }
    iVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x17e,
                          "mac_frame_get_dstaddr","index != 0xff");
  }
  if (iVar4 != 0xff) {
    *extraout_a1 = 2;
    *(undefined2 *)(extraout_a1 + 2) = *(undefined2 *)((int)puVar7 + iVar4);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x184,
                "mac_frame_get_dstaddr","index != 0xff");
_L0:
  *extraout_a1 = 0;
  return;
}

