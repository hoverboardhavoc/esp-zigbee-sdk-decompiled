/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_message_notify_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_message_notify_attr_value
               (uint8_t dst_ep,uint16_t cluster_id,uint8_t role,zcl_attr_desc_t *attr_desc)

{
  uint16_t uVar1;
  int iStack_28;
  zcl_set_attr_value_message_t message;
  
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.attribute.id = 0;
  message.in.attribute._2_2_ = 0;
  message.in.attribute.data.type = '\0';
  message.in.attribute.data._1_1_ = 0;
  message.in.attribute.data.size = 0;
  message.in.attribute.data.value = (void *)0x0;
  iStack_28 = (uint)CONCAT21(cluster_id,dst_ep) << 8;
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.status = role;
  if (attr_desc != (zcl_attr_desc_t *)0x0) {
    message._6_2_ = 0;
    message.info._4_2_ = attr_desc->id;
    message.in.attribute._1_3_ = 0;
    message.in.attribute.id._0_1_ = attr_desc->type;
    uVar1 = zcl_get_attr_value_size(attr_desc->type,attr_desc->data_p);
    message.in.attribute._2_2_ = uVar1;
    message.in.attribute.data._0_4_ = attr_desc->data_p;
  }
  message.in.attribute.data.value = (void *)CONCAT31(message.in.attribute.data.value._1_3_,0xfe);
  zcl_core_action_schedule(0,&iStack_28);
  return;
}

