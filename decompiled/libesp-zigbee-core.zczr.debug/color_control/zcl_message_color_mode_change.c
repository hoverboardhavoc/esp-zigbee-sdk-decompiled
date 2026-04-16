/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> zcl_message_color_mode_change
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_color_mode_change
          (zcl_packet_t *packet,uint8_t new_mode,uint8_t old_mode,
          ezb_zcl_color_control_color_t *color)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uStack_38;
  ezb_zcl_color_control_color_mode_change_message_t message;
  
  uStack_38 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.old_mode = '\0';
  message.in.new_mode = '\0';
  message.in._6_2_ = 0;
  message.out.result = '\0';
  message.out._1_1_ = 0;
  message.out.color.mode = '\0';
  message.out.color._1_1_ = 0;
  uVar2 = zcl_packet_to_message(&uStack_38,packet);
  if (uVar2 == 0) {
    message.in.header._0_2_ = CONCAT11(new_mode,old_mode);
    message.in.old_mode = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x1b,&uStack_38);
    uVar1 = message.in._4_4_;
    if (message.in.old_mode == '\0') {
      color->mode = message.in._6_1_;
      color->field_0x1 = message.in._7_1_;
      (color->field_1).field_0.field_0 =
           (anon_union_2_2_90419b2c_for_anon_struct_4_2_5cb415c6_for_anon_union_4_3_e2189aaa_for_ezb_zcl_color_control_color_t_1_0_0
            )message.out._0_2_;
      (color->field_1).field_1.y = message.out.color._0_2_;
    }
    uVar2 = uVar1 & 0xff;
  }
  return (ezb_zcl_status_t)uVar2;
}

