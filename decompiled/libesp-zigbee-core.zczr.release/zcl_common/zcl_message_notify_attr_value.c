/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_message_notify_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_message_notify_attr_value
               (uint8_t dst_ep,uint16_t cluster_id,uint8_t role,zcl_attr_desc_t *attr_desc)

{
  undefined1 uStack_38;
  uint8_t uStack_37;
  uint16_t uStack_36;
  zcl_set_attr_value_message_t message;
  
  memset(&uStack_38,0,0x18);
  uStack_37 = dst_ep;
  uStack_36 = cluster_id;
  message.info.status = role;
  if (attr_desc != (zcl_attr_desc_t *)0x0) {
    message.info._4_2_ = attr_desc->id;
    message.in.attribute.id._0_1_ = attr_desc->type;
    message.in.attribute._2_2_ =
         zcl_get_attr_value_size((zcl_attr_type_t)message.in.attribute.id,attr_desc->data_p);
    message.in.attribute.data._0_4_ = attr_desc->data_p;
  }
  message.in.attribute.data.value._0_1_ = 0xfe;
  zcl_core_action_schedule(0,&uStack_38);
  return;
}

