/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_set_srcaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_frame_set_srcaddr(ezb_radio_frame_t *frame,ezb_address_t *address)

{
  ezb_grpaddr_t eVar1;
  ushort *puVar2;
  uint8_t uVar3;
  uint16_t extraout_a0;
  ushort fcf;
  undefined3 extraout_var;
  ezb_grpaddr_t *peVar4;
  
  puVar2 = (ushort *)frame->psdu;
  fcf = *puVar2;
  if (0x3fff < fcf) goto _L78;
  while( true ) {
    address = (ezb_address_t *)__assert_func(0,0,0,0);
    fcf = extraout_a0;
_L78:
    uVar3 = mac_fcf_skip_src_panid_index(fcf);
    peVar4 = (ezb_grpaddr_t *)(CONCAT31(extraout_var,uVar3) + (int)puVar2);
    if (address->addr_mode == '\x02') break;
    if (address->addr_mode == '\x03') {
      eVar1 = *(ezb_grpaddr_t *)((int)&address->u + 4);
      *peVar4 = (address->u).group_addr;
      peVar4[1] = eVar1;
      return;
    }
  }
  peVar4->group = (address->u).short_addr;
  return;
}

