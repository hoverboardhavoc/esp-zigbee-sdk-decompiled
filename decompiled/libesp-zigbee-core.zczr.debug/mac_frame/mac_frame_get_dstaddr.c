/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_get_dstaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_frame_get_dstaddr(ezb_radio_frame_t *frame,ezb_address_t *address)

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
  uVar1 = mac_fcf_find_dstaddr_index(fcf);
  iVar2 = CONCAT31(extraout_var,uVar1);
  if ((fcf & 0xc00) != 0x800) {
    if ((fcf & 0xc00) != 0xc00) {
      if ((fcf & 0xc00) != 0) {
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
    iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x17e,
                          "mac_frame_get_dstaddr","index != 0xff");
  }
  if (iVar2 != 0xff) {
    address->addr_mode = '\x02';
    (address->u).short_addr = *(ezb_shortaddr_t *)((int)puVar5 + iVar2);
    return 0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x184,
                "mac_frame_get_dstaddr","index != 0xff");
_L0:
  address->addr_mode = '\0';
  return 0;
}

