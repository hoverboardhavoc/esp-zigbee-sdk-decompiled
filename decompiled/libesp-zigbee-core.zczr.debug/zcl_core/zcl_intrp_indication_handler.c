/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_intrp_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_intrp_indication_handler(af_intrp_data_ind_t *ind)

{
  int iVar1;
  undefined4 uStack_38;
  zcl_packet_t packet;
  
  uStack_38 = 0;
  packet.header.src_addr._0_4_ = 0;
  packet.header.src_addr.u._2_4_ = 0;
  packet.header._8_4_ = 0;
  packet.header.dst_addr.u._0_2_ = 0;
  packet.header.dst_addr.u._2_2_ = 0;
  packet.header.dst_addr.u._4_4_ = 0;
  packet.header.src_ep = '\0';
  packet.header.dst_ep = '\0';
  packet.header.cluster_id = 0;
  packet.header.profile_id = 0;
  packet.header.fc = '\0';
  packet.header._27_1_ = 0;
  packet.header.manuf_code = 0;
  packet.header.tsn = '\0';
  packet.header.rssi = '\0';
  packet.header.cmd_id = '\0';
  packet.header._33_1_ = 0;
  packet._34_2_ = 0;
  iVar1 = zcl_packet_init_with_intrp_ind(&uStack_38,ind);
  if (iVar1 == 0) {
    if ((packet.header._20_4_ & 0xffff) == 0xc05e) {
      iVar1 = zcl_touchlink_handler(&uStack_38);
      if (iVar1 == 0) goto _L0;
    }
    else {
      iVar1 = 0x85;
    }
  }
  else {
    iVar1 = 0xfe;
  }
  if (iVar1 != 0xfe) {
    iVar1 = zcl_packet_send_default_response(&uStack_38,iVar1);
  }
_L0:
  return (zcl_status_t)iVar1;
}

