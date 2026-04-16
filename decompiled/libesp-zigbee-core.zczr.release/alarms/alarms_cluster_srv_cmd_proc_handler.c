/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarms_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t alarms_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  uint8_t ep_id;
  uint16_t cluster_id;
  uint16_t uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  alarms_alarm_table_t *paVar8;
  alarms_alarm_table_entry_t *paVar9;
  ezb_err_t eVar10;
  undefined4 uVar11;
  list_node_t time_stamp;
  list_t *plVar12;
  list_t *plVar13;
  uint16_t uStack_6e;
  uint32_t uStack_6c;
  uint16_t offset;
  ezb_zcl_alarms_reset_alarm_message_t message;
  zcl_packet_t rsp;
  
  memset(&message.out,0,0x28);
  iVar5 = 1;
  if (arg == (void *)0x0) goto _L0;
  iVar5 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar5 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar5 != 0))
  goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 2) {
    paVar9 = alarm_table_pop_oldest(*(uint8_t *)((int)arg + 0x15));
    if (paVar9 != (alarms_alarm_table_entry_t *)0x0) {
      uStack_6c = (uint)uStack_6c._1_3_ << 8;
      iVar6 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff94);
      if (iVar6 == 0) {
        uStack_6c = CONCAT31(uStack_6c._1_3_,paVar9->alarm_code);
        iVar6 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff94);
        if (iVar6 == 0) {
          uStack_6c = CONCAT22(offset,paVar9->cluster_id);
          iVar6 = zmsg_append_bytes(rsp._32_4_,2,&stack0xffffff94);
          if (iVar6 == 0) {
            uStack_6c = paVar9->time_stamp;
            uVar11 = 4;
            goto _L0;
          }
        }
      }
_L0:
      uVar3 = 0x89;
      goto _L0;
    }
    uStack_6c = CONCAT31(uStack_6c._1_3_,0x8b);
    uVar11 = 1;
_L0:
    iVar6 = zmsg_append_bytes(rsp._32_4_,uVar11,&stack0xffffff94);
    if (iVar6 != 0) goto _L0;
    uVar3 = zcl_packet_setup_response(&message.out,arg,1);
    if (uVar3 != 0) goto _L0;
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 == 0) {
        uStack_6c = 0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        message.in.payload.alarm_code = '\0';
        message.in.payload._1_1_ = 0;
        message.in.payload.cluster_id = 0;
        uStack_6e = 0;
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_6e,(uint8_t *)&message.in);
        uVar3 = (uint)uStack_6e;
        iVar6 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar3,2,
                                (undefined1 *)((int)&message.in.header + 2));
        if (iVar6 == 0) {
          uVar4 = 0xffff;
        }
        else {
          uVar4 = uVar3 + iVar6 & 0xffff;
        }
        uStack_6e = (uint16_t)uVar4;
        uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        uVar3 = 0x80;
        if ((uVar4 <= uVar7) &&
           (uVar3 = zcl_packet_to_message(&stack0xffffff94,arg,0x80), uVar3 == 0)) {
          ep_id = *(uint8_t *)((int)arg + 0x15);
          uVar3 = (uint)message.in.header & 0xff;
          uVar2 = message.in.header._2_2_;
          paVar8 = get_alarm_table(ep_id);
          if (paVar8 != (alarms_alarm_table_t *)0x0) {
            iVar6 = 5;
            plVar12 = &paVar8->active_alarms;
            while (plVar13 = plVar12, plVar12 = (list_t *)plVar13->head, plVar12 != (list_t *)0x0) {
              bVar1 = *(byte *)(plVar12 + 1);
              if ((uVar3 == bVar1) &&
                 (cluster_id = *(uint16_t *)((int)(plVar12 + 1) + 2), uVar2 == cluster_id)) {
                if (plVar12 == (list_t *)paVar8->tail) {
                  paVar8->tail = (list_node_t *)
                                 ((uint)plVar13 & -(uint)(&paVar8->active_alarms != plVar13));
                }
                time_stamp.next = plVar12[2].head;
                plVar13->head = plVar13->head->next;
                plVar12->head = (list_node_t *)plVar12;
                alarm_table_remove_stored_entry(ep_id,bVar1,cluster_id,(uint32_t)time_stamp.next);
                iVar6 = 0;
                paVar8->count = paVar8->count + 0xff;
                plVar12 = plVar13;
              }
            }
            if (iVar6 == 0) {
              message.in.payload.alarm_code = 0xfe;
              message._4_4_ = arg;
              zcl_core_action_schedule(0x35,&stack0xffffff94);
              uVar3 = (uint)message.in.payload & 0xff;
              if (((uint)message.in.payload & 0xff) == 0xfe) {
                uVar3 = 1;
              }
              goto _L0;
            }
          }
          uVar3 = 0x8b;
        }
      }
      else {
        uStack_6c = 0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        uVar3 = zcl_packet_to_message(&stack0xffffff94,arg);
        if (uVar3 == 0) {
          message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,0xfe);
          message._4_4_ = arg;
          zcl_core_action_schedule(0x36,&stack0xffffff94,0);
          uVar4 = (uint)message.in.header & 0xff;
          if (uVar4 == 0xfe) {
            uVar4 = 0;
          }
          eVar10 = alarm_table_reset(*(uint8_t *)((int)arg + 0x15));
          uVar3 = 0x8b;
          if (eVar10 == 0) {
            uVar3 = 1;
            if ((char)message.in.header != -2) {
              uVar3 = uVar4;
            }
          }
        }
      }
    }
    else if (bVar1 == 3) {
      alarm_table_reset(*(uint8_t *)((int)arg + 0x15));
      uVar3 = 0;
    }
    else {
      uVar3 = 0x81;
    }
_L0:
    iVar6 = zcl_packet_setup_default_response(&message.out,arg,uVar3);
    if (iVar6 != 0) {
      zcl_packet_free(&message.out);
      iVar5 = iVar6;
      goto _L0;
    }
  }
  zcl_packet_send(&message.out,0);
_L0:
  return (ezb_zcl_status_t)iVar5;
}

