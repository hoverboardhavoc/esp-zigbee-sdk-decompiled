/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

void ias_zone_cluster_srv_write_attr_hook
               (uint8_t ep_id,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  ushort uVar1;
  ushort uVar2;
  ias_zone_srv_zone_ctx_t *piVar3;
  zcl_attr_desc_t *pzVar4;
  int iVar5;
  undefined2 in_register_0000202e;
  int extraout_a1;
  undefined1 auStack_70 [22];
  ushort uStack_5a;
  undefined1 auStack_58 [4];
  ias_zone_status_change_notif_cmd_t cmd;
  zcl_packet_t packet;
  
  iVar5 = CONCAT22(in_register_0000202e,attr_id);
  if (new_value == (void *)0x0) {
    piVar3 = ias_zone_srv_get_zone_ctx(ep_id);
    ep_id = (uint8_t)piVar3;
    iVar5 = extraout_a1;
  }
  if (iVar5 == 2) {
    pzVar4 = ias_zone_srv_get_attr_desc(ep_id,0);
    if (pzVar4 != (zcl_attr_desc_t *)0x0) goto _L0;
    do {
      do {
        pzVar4 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
_L0:
                    /* WARNING: Load size is inaccurate */
        if (*pzVar4->data_p != '\x01') {
          return;
        }
        pzVar4 = ias_zone_srv_get_attr_desc(ep_id,2);
      } while (pzVar4 == (zcl_attr_desc_t *)0x0);
                    /* WARNING: Load size is inaccurate */
      uVar1 = *new_value;
      new_value = (void *)(uint)uVar1;
                    /* WARNING: Load size is inaccurate */
      uVar2 = *pzVar4->data_p;
      if ((~(uVar2 & 0x3cf) & (uint)new_value & 0x3cf) == 0) {
        if ((~(uint)new_value & (uint)uVar2) == 0) {
          return;
        }
        if ((uVar2 & 0x20) == 0) {
          return;
        }
      }
      memset(auStack_58,0,0x20);
      pzVar4 = ias_zone_srv_get_attr_desc(ep_id,0x11);
    } while (pzVar4 == (zcl_attr_desc_t *)0x0);
    cmd.cmd_ctrl.cnf_ctx.user_ctx._2_1_ = 0;
                    /* WARNING: Load size is inaccurate */
    cmd.cmd_ctrl.cnf_ctx.user_ctx._3_1_ = *pzVar4->data_p;
    cmd.payload.zone_status = 0;
    auStack_58[0] = 0;
    cmd.cmd_ctrl.dst_addr.u._5_1_ = ep_id;
    cmd.cmd_ctrl.cnf_ctx.user_ctx._0_2_ = uVar1;
    memset(&cmd.payload.delay,0,0x28);
    iVar5 = zcl_packet_init(&cmd.payload.delay,0);
    if (iVar5 == 0) {
      memcpy(auStack_70,auStack_58,10);
      iVar5 = zcl_cmd_to_packet(&cmd.payload.delay,1,0,1,cmd.cmd_ctrl.dst_addr.u._6_1_,0,0,0x500);
      if (iVar5 == 0) {
        uStack_5a = (ushort)cmd.cmd_ctrl.cnf_ctx.user_ctx;
        iVar5 = zmsg_append_bytes(packet._32_4_,2,&uStack_5a);
        if (iVar5 == 0) {
          uStack_5a = CONCAT11(uStack_5a._1_1_,cmd.cmd_ctrl.cnf_ctx.user_ctx._2_1_);
          iVar5 = zmsg_append_bytes(packet._32_4_,1,&uStack_5a);
          if (iVar5 == 0) {
            uStack_5a = CONCAT11(uStack_5a._1_1_,cmd.cmd_ctrl.cnf_ctx.user_ctx._3_1_);
            iVar5 = zmsg_append_bytes(packet._32_4_,1,&uStack_5a);
            if (iVar5 == 0) {
              uStack_5a = cmd.payload.zone_status;
              iVar5 = zmsg_append_bytes(packet._32_4_,2,&uStack_5a);
              if (iVar5 == 0) {
                zcl_packet_send(&cmd.payload.delay,&cmd.cmd_ctrl.dis_default_rsp);
                iVar5 = zcl_status_to_err();
                if (iVar5 == 0) {
                  return;
                }
              }
            }
          }
        }
      }
    }
    zcl_packet_free(&cmd.payload.delay);
  }
  return;
}

