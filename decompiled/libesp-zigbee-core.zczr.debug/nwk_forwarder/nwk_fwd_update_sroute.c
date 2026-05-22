/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x149,
                  "nwk_fwd_update_sroute","nwk_fcf_is_source_routing(fcf)");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x152,
                  "nwk_fwd_update_sroute","sroute.relay_index < sroute.relay_count");
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

