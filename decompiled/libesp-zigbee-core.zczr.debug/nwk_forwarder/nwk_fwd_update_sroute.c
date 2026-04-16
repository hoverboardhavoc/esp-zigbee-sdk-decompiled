/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_update_sroute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: sroute */
/* WARNING: Unknown calling convention */

void nwk_fwd_update_sroute(zmsg_t *msg,uint16_t fcf,nwk_tx_info_t *tx_info)

{
  uint8_t uVar1;
  undefined3 extraout_var;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  nwk_sroute_field_t sroute;
  int iVar2;
  
  if ((fcf & 0x400) == 0) {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x10e,"nwk_fwd_update_sroute",
                  "nwk_fcf_is_source_routing(fcf)");
_L0:
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x117,"nwk_fwd_update_sroute",
                  "sroute.relay_index < sroute.relay_count");
  }
  else {
    uVar1 = nwk_fcf_get_hdr_size(fcf);
    iVar2 = CONCAT31(extraout_var,uVar1);
    zmsg_read_bytes(msg,iVar2,2,&bStack_14);
    if (bStack_13 != 0) {
      bStack_15 = bStack_13 - 1;
      bStack_13 = bStack_15;
      if (bStack_15 < bStack_14) {
        zmsg_write_bytes(msg,iVar2 + 1U & 0xffff,1,&bStack_15);
        zmsg_read_bytes(msg,(iVar2 + (uint)bStack_13 * 2 & 0xffff) + 2 & 0xffff,2,
                        &tx_info->mac_dst_addr);
        goto _L0;
      }
      goto _L0;
    }
  }
  zmsg_read_bytes(msg,2,&tx_info->mac_dst_addr);
_L0:
  tx_info->iface_id = '\0';
  return;
}

