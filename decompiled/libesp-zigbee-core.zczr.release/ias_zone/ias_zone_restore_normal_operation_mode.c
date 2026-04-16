/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_restore_normal_operation_mode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ias_zone_restore_normal_operation_mode(void *ctx)

{
  byte ep_id;
  undefined4 uVar1;
  undefined4 uVar2;
  ias_zone_srv_zone_ctx_t *piVar3;
  zcl_attr_desc_t *pzVar4;
  undefined4 uStack_18;
  ezb_zcl_ias_zone_initiate_normal_mode_message_t message;
  
  uStack_18 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  if (ctx != (void *)0x0) goto _L0;
  do {
    ctx = (void *)__assert_func(0,0,0,0);
_L0:
    ep_id = (byte)ctx;
    piVar3 = ias_zone_srv_get_zone_ctx(ep_id);
    uVar1 = message.info._0_4_;
    message.info.status = '\x01';
    uVar2 = message.info._0_4_;
    uStack_18 = CONCAT22(0x500,(ushort)ep_id << 8);
    message.info.cluster_id._1_1_ = SUB41(uVar1,3);
    message.info._0_2_ = (undefined2)uVar2;
    message.info.cluster_id._0_1_ = 0xfe;
    zcl_core_action_schedule(0x2f,&uStack_18);
    pzVar4 = ias_zone_srv_get_attr_desc(ep_id,0x13);
  } while (pzVar4 == (zcl_attr_desc_t *)0x0);
  if (piVar3->is_prev_sensitivity_level_set != false) {
    *(uint8_t *)pzVar4->data_p = piVar3->prev_sensitivity_level;
    piVar3->is_prev_sensitivity_level_set = false;
  }
  return;
}

