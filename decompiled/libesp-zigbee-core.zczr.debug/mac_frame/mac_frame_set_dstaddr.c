/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_set_dstaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_frame_set_dstaddr(ezb_radio_frame_t *frame,ezb_address_t *address)

{
  ushort fcf;
  ezb_grpaddr_t eVar1;
  uint16_t *puVar2;
  uint8_t uVar3;
  undefined3 extraout_var;
  undefined4 *puVar4;
  undefined3 extraout_var_00;
  int iVar5;
  undefined1 *extraout_a1;
  undefined4 uVar6;
  undefined4 uVar7;
  ushort *puVar8;
  
  puVar2 = (uint16_t *)frame->psdu;
  uVar3 = mac_fcf_find_dstaddr_index(*puVar2);
  iVar5 = CONCAT31(extraout_var,uVar3);
  if (iVar5 == 0xff) {
    iVar5 = __assert_func("//build/esp-zigbee/src/core/mac/mac_frame.c",0x19c,
                          "mac_frame_set_dstaddr","(index != 0xff)");
_L0:
    *(ezb_shortaddr_t *)((int)puVar2 + iVar5) = (address->u).short_addr;
    return;
  }
  if (address->addr_mode == '\x02') goto _L0;
  if (address->addr_mode == '\x03') {
    eVar1 = *(ezb_grpaddr_t *)((int)&address->u + 4);
    *(ezb_grpaddr_t *)(iVar5 + (int)puVar2) = (address->u).group_addr;
    ((ezb_grpaddr_t *)(iVar5 + (int)puVar2))[1] = eVar1;
    return;
  }
  puVar4 = (undefined4 *)
           __assert_func("//build/esp-zigbee/src/core/mac/mac_frame.c",0x1a8,"mac_frame_set_dstaddr"
                         ,&_LC4);
  puVar8 = (ushort *)*puVar4;
  fcf = *puVar8;
  uVar3 = mac_fcf_find_srcaddr_index(fcf);
  iVar5 = CONCAT31(extraout_var_00,uVar3);
  if ((fcf & 0xc000) != 0x8000) {
    if ((fcf & 0xc000) != 0xc000) {
      if ((fcf & 0xc000) != 0) {
        *extraout_a1 = 0;
        return;
      }
      goto _L0;
    }
    if (iVar5 != 0xff) {
      *extraout_a1 = 3;
      uVar6 = *(undefined4 *)(iVar5 + (int)puVar8);
      uVar7 = ((undefined4 *)(iVar5 + (int)puVar8))[1];
      *(short *)(extraout_a1 + 2) = (short)uVar6;
      *(short *)(extraout_a1 + 4) = (short)((uint)uVar6 >> 0x10);
      *(short *)(extraout_a1 + 6) = (short)uVar7;
      *(short *)(extraout_a1 + 8) = (short)((uint)uVar7 >> 0x10);
      return;
    }
    iVar5 = __assert_func("//build/esp-zigbee/src/core/mac/mac_frame.c",0x1b8,
                          "mac_frame_get_srcaddr","(index != 0xff)");
  }
  if (iVar5 != 0xff) {
    *extraout_a1 = 2;
    *(undefined2 *)(extraout_a1 + 2) = *(undefined2 *)((int)puVar8 + iVar5);
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/mac/mac_frame.c",0x1be,"mac_frame_get_srcaddr",
                "(index != 0xff)");
_L0:
  *extraout_a1 = 0;
  return;
}

