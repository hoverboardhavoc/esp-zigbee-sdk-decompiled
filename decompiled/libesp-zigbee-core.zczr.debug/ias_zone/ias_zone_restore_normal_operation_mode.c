/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_restore_normal_operation_mode
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
  int iVar5;
  short *psVar6;
  char *pcVar7;
  short sVar8;
  undefined4 uStack_18;
  ezb_zcl_ias_zone_initiate_normal_mode_message_t message;
  
  uStack_18 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  if (ctx == (void *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xb3,
                  "ias_zone_restore_normal_operation_mode",&_L0);
  }
  else {
    ep_id = (byte)ctx;
    piVar3 = ias_zone_srv_get_zone_ctx(ep_id);
    uVar1 = message.info._0_4_;
    uStack_18 = CONCAT22(0x500,(ushort)ep_id << 8);
    message.info.status = '\x01';
    uVar2 = message.info._0_4_;
    message.info.cluster_id._1_1_ = SUB41(uVar1,3);
    message.info._0_2_ = (undefined2)uVar2;
    message.info.cluster_id._0_1_ = 0xfe;
    zcl_core_action_schedule(0x2f,&uStack_18);
    pzVar4 = ias_zone_srv_get_attr_desc(ep_id,0x13);
    if (pzVar4 != (zcl_attr_desc_t *)0x0) {
      if (piVar3->is_prev_sensitivity_level_set != false) {
        *(uint8_t *)pzVar4->data_p = piVar3->prev_sensitivity_level;
        piVar3->is_prev_sensitivity_level_set = false;
      }
      return;
    }
  }
  pcVar7 = "ias_zone_restore_normal_operation_mode";
  psVar6 = (short *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c"
                                  ,0xbf,"ias_zone_restore_normal_operation_mode","attr_desc");
  iVar5 = zmsg_read_bytes(*psVar6,1,pcVar7);
  if (iVar5 == 0) {
    sVar8 = -1;
  }
  else {
    sVar8 = *psVar6 + (short)iVar5;
  }
  *psVar6 = sVar8;
  return;
}

