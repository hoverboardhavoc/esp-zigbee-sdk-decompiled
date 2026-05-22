/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_set_srcaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_frame_set_srcaddr(ezb_radio_frame_t *frame,ezb_address_t *address)

{
  ezb_grpaddr_t eVar1;
  uint16_t *puVar2;
  uint8_t uVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 *puVar5;
  
  puVar2 = (uint16_t *)frame->psdu;
  uVar3 = mac_fcf_find_srcaddr_index(*puVar2);
  iVar4 = CONCAT31(extraout_var,uVar3);
  if (iVar4 == 0xff) {
    iVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x1d5,
                          "mac_frame_set_srcaddr","(index != 0xff)");
  }
  else if (address->addr_mode != '\x02') {
    if (address->addr_mode == '\x03') {
      eVar1 = *(ezb_grpaddr_t *)((int)&address->u + 4);
      *(ezb_grpaddr_t *)(iVar4 + (int)puVar2) = (address->u).group_addr;
      ((ezb_grpaddr_t *)(iVar4 + (int)puVar2))[1] = eVar1;
      return;
    }
    puVar5 = (undefined4 *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x1e1,
                           "mac_frame_set_srcaddr",&_LC4);
    if ((*(ushort *)*puVar5 & 0x200) == 0) {
      mac_fcf_skip_addr_field_index(*(ushort *)*puVar5);
    }
    return;
  }
  *(ezb_shortaddr_t *)((int)puVar2 + iVar4) = (address->u).short_addr;
  return;
}

