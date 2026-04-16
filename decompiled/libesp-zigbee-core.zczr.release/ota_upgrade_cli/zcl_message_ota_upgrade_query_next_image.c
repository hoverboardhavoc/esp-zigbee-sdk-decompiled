/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> zcl_message_ota_upgrade_query_next_image
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_ota_upgrade_query_next_image
          (zcl_packet_t *packet,ota_upgrade_query_next_image_rsp_t *rsp)

{
  uint uVar1;
  undefined1 auStack_38 [4];
  ezb_zcl_ota_upgrade_query_next_image_rsp_message_t message;
  
  memset(auStack_38,0,0x28);
  uVar1 = zcl_packet_to_message(auStack_38,packet);
  if (uVar1 == 0) {
    message.in.header._0_1_ = rsp->status;
    message.in.image.server_address.field_0.u8[4] = (packet->header).src_ep;
    message.in.image.server_address.field_0.u64._5_2_ = rsp->manuf_code;
    message.in.image._8_2_ = rsp->image_type;
    message.in.image._12_4_ = rsp->file_version;
    message.in.image.file_version = rsp->image_size;
    message._4_4_ = packet;
    nwk_address_extended_by_short
              ((packet->header).src_addr.u.short_addr,(undefined1 *)((int)&message.in.header + 1));
    message.in.image.size._0_1_ = 0xfe;
    zcl_core_action_schedule(0x3b,auStack_38);
    if ((byte)message.in.image.size != 0xfe) {
      uVar1 = (uint)(byte)message.in.image.size;
    }
  }
  return (ezb_zcl_status_t)uVar1;
}

