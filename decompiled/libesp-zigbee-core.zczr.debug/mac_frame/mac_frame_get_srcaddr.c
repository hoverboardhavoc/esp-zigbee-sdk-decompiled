/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_get_srcaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_frame_get_srcaddr(ezb_radio_frame_t *frame,ezb_address_t *address)

{
  ushort fcf;
  uint8_t uVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  
  puVar5 = (ushort *)frame->psdu;
  fcf = *puVar5;
  uVar1 = mac_fcf_find_srcaddr_index(fcf);
  iVar2 = CONCAT31(extraout_var,uVar1);
  if ((fcf & 0xc000) != 0x8000) {
    if ((fcf & 0xc000) != 0xc000) {
      if ((fcf & 0xc000) != 0) {
        address->addr_mode = '\0';
        return 0x10;
      }
      goto _L0;
    }
    if (iVar2 != 0xff) {
      address->addr_mode = '\x03';
      uVar3 = *(undefined4 *)(iVar2 + (int)puVar5);
      uVar4 = ((undefined4 *)(iVar2 + (int)puVar5))[1];
      (address->u).short_addr = (ezb_shortaddr_t)uVar3;
      (address->u).group_addr.bcast = (ezb_shortaddr_t)((uint)uVar3 >> 0x10);
      *(short *)((int)&address->u + 4) = (short)uVar4;
      *(short *)((int)&address->u + 6) = (short)((uint)uVar4 >> 0x10);
      return 0;
    }
    iVar2 = __assert_func("//build/esp-zigbee/src/core/mac/mac_frame.c",0x1b8,
                          "mac_frame_get_srcaddr","(index != 0xff)");
  }
  if (iVar2 != 0xff) {
    address->addr_mode = '\x02';
    (address->u).short_addr = *(ezb_shortaddr_t *)((int)puVar5 + iVar2);
    return 0;
  }
  __assert_func("//build/esp-zigbee/src/core/mac/mac_frame.c",0x1be,"mac_frame_get_srcaddr",
                "(index != 0xff)");
_L0:
  address->addr_mode = '\0';
  return 0;
}

