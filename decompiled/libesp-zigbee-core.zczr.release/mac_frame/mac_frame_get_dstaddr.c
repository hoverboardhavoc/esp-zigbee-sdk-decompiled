/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_get_dstaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_frame_get_dstaddr(ezb_radio_frame_t *frame,ezb_address_t *address)

{
  ushort fcf;
  ushort *puVar1;
  undefined4 *puVar2;
  uint8_t uVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = (ushort *)frame->psdu;
  fcf = *puVar1;
  if ((fcf & 0xc00) == 0) {
    address->addr_mode = '\0';
  }
  else {
    uVar3 = mac_fcf_skip_dst_panid_index(fcf);
    if ((fcf & 0xc00) == 0x800) {
      address->addr_mode = '\x02';
      (address->u).short_addr = *(ezb_shortaddr_t *)((int)puVar1 + CONCAT31(extraout_var,uVar3));
    }
    else {
      if ((fcf & 0xc00) != 0xc00) {
        address->addr_mode = '\0';
        return 0x10;
      }
      address->addr_mode = '\x03';
      puVar2 = (undefined4 *)((int)puVar1 + CONCAT31(extraout_var,uVar3));
      uVar4 = *puVar2;
      uVar5 = puVar2[1];
      (address->u).short_addr = (ezb_shortaddr_t)uVar4;
      *(short *)((int)&address->u + 4) = (short)uVar5;
      (address->u).group_addr.bcast = (ezb_shortaddr_t)((uint)uVar4 >> 0x10);
      *(short *)((int)&address->u + 6) = (short)((uint)uVar5 >> 0x10);
    }
  }
  return 0;
}

