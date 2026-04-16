/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_pal_callback_rx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_pal_callback_rx_done(ezb_radio_frame_t *frame,ezb_err_t rx_error)

{
  uint8_t uVar1;
  mac_device *dev;
  dlist_node_s *pdVar2;
  int iVar3;
  uint uVar4;
  mac_operation_t op;
  undefined4 uVar5;
  dlist_node_s *pdVar6;
  ezb_grpaddr_t eVar7;
  dlist_node_s *pdVar8;
  active_scan_callback p_Var9;
  undefined1 auStack_70 [4];
  mac_poll_ind_t poll_ind;
  ushort uStack_62;
  mac_beacon_notify_ind_t beacon_ind;
  mac_frame_t mac_frame;
  
  dev = s_devices;
  if (rx_error != 0) {
    return;
  }
  if ((*(uint *)&(s_devices->ctx).field_0x70 & 1) == 0) {
    return;
  }
  if (frame == (ezb_radio_frame_t *)0x0) {
    return;
  }
  if (frame->psdu == (uint8_t *)0x0) {
    return;
  }
  iVar3 = mac_frame_parse(&beacon_ind.beacon_payload);
  if (iVar3 != 0) {
    return;
  }
  iVar3 = mac_filter_apply_to_rxframe(&beacon_ind.beacon_payload);
  if (iVar3 != 0) {
    return;
  }
  if ((mac_frame.mhr.dst_panid & 8) != 0) {
    return;
  }
  uVar1 = (dev->ctx).cur_op;
  if (uVar1 == '\x01') {
    if ((mac_frame.mhr.dst_panid & 7) == 0) {
      p_Var9 = (dev->ctx).field_7.active_scan_result_handler;
      if (p_Var9 == (active_scan_callback)0x0) {
        return;
      }
      memset((void *)((int)&poll_ind.device_address.u + 6),0,0x1c);
      if ((byte)mac_frame.mhr.fcf < 4) {
        return;
      }
      if (*(char *)(mac_frame.mpl._0_4_ + 2) != '\0') {
        return;
      }
      if (*(char *)(mac_frame.mpl._0_4_ + 3) != '\0') {
        return;
      }
      if ((~*(ushort *)mac_frame.mpl._0_4_ & 0xfff) != 0) {
        return;
      }
      stack0xffffff9c =
           CONCAT12((mac_frame.mhr.dst_panid & 0x3000) == 0x2000,poll_ind.device_address.u._6_2_);
      if (mac_frame.mhr.dst_addr.u._4_1_ == '\0') {
        return;
      }
      memcpy(&beacon_ind,(void *)((int)&mac_frame.mhr.dst_addr.u + 4),10);
      beacon_ind.pan_descriptor.coord_addr.u._4_2_ = mac_frame.mhr.src_addr.u._6_2_;
      if (mac_frame.mhr.src_addr.u._6_2_ == -1) {
        beacon_ind.pan_descriptor.coord_addr.u._4_2_ = mac_frame.mhr.src_addr.u._4_2_;
      }
      beacon_ind.pan_descriptor.superframe_spec._0_1_ = (byte)mac_frame.mhr.fcf - 4;
      beacon_ind._20_4_ = mac_frame.mpl._0_4_ + 4;
      beacon_ind.pan_descriptor.coord_addr.u._7_1_ = beacon_ind.beacon_payload[5];
      beacon_ind.pan_descriptor.channel_page = beacon_ind.beacon_payload[0x11];
      beacon_ind.pan_descriptor.channel_number = beacon_ind.beacon_payload[0x10];
      beacon_ind.pan_descriptor.coord_panid = *(ezb_panid_t *)mac_frame.mpl._0_4_;
      poll_ind.device_address.u._6_2_ =
           CONCAT11((undefined1)mac_frame.mhr.src_panid,poll_ind.device_address.u._6_1_);
      (*p_Var9)((active_scan_result_t *)((int)&poll_ind.device_address.u + 6),
                (dev->ctx).scan_user_ctx);
      return;
    }
_L0:
    if ((dev->ctx).pan_channel != (dev->ctx).scan_channel) {
      return;
    }
  }
  else if (uVar1 == '\x02') goto _L0;
  if ((mac_frame.mhr.dst_panid & 7) != 1) {
    if ((mac_frame.mhr.dst_panid & 7) != 3) {
      if ((mac_frame.mhr.dst_panid & 7) != 0) {
        return;
      }
      memset((void *)((int)&poll_ind.device_address.u + 6),0,0x1c);
      if ((byte)mac_frame.mhr.fcf < 4) {
        return;
      }
      if (*(char *)(mac_frame.mpl._0_4_ + 2) != '\0') {
        return;
      }
      if (*(char *)(mac_frame.mpl._0_4_ + 3) != '\0') {
        return;
      }
      if ((~*(ushort *)mac_frame.mpl._0_4_ & 0xfff) != 0) {
        return;
      }
      stack0xffffff9c =
           CONCAT12((mac_frame.mhr.dst_panid & 0x3000) == 0x2000,poll_ind.device_address.u._6_2_);
      if (mac_frame.mhr.dst_addr.u._4_1_ == '\0') {
        return;
      }
      memcpy(&beacon_ind,(void *)((int)&mac_frame.mhr.dst_addr.u + 4),10);
      beacon_ind.pan_descriptor.coord_addr.u._4_2_ = mac_frame.mhr.src_addr.u._6_2_;
      if (mac_frame.mhr.src_addr.u._6_2_ == -1) {
        beacon_ind.pan_descriptor.coord_addr.u._4_2_ = mac_frame.mhr.src_addr.u._4_2_;
      }
      beacon_ind._20_4_ = mac_frame.mpl._0_4_ + 4;
      beacon_ind.pan_descriptor.superframe_spec._0_1_ = (byte)mac_frame.mhr.fcf - 4;
      beacon_ind.pan_descriptor.coord_addr.u._7_1_ = beacon_ind.beacon_payload[5];
      beacon_ind.pan_descriptor.channel_page = beacon_ind.beacon_payload[0x11];
      beacon_ind.pan_descriptor.channel_number = beacon_ind.beacon_payload[0x10];
      beacon_ind.pan_descriptor.coord_panid = *(ezb_panid_t *)mac_frame.mpl._0_4_;
      poll_ind.device_address.u._6_2_ =
           CONCAT11((undefined1)mac_frame.mhr.src_panid,poll_ind.device_address.u._6_1_);
      nwk_mm_beacon_notify_indication
                ((dev->ctx).iface_id,(undefined1 *)((int)&poll_ind.device_address.u + 6));
      return;
    }
    uVar4 = (uint)*(byte *)mac_frame.mpl._0_4_;
    if (uVar4 != 4) {
      if (uVar4 < 5) {
        if (uVar4 == 1) {
          if (((dev->pib).field_0x2a & 1) == 0) {
            return;
          }
          if (mac_frame.mhr.dst_addr.u._4_1_ != '\x03') {
            return;
          }
          stack0xffffff9c = mac_frame.mhr._8_4_;
          beacon_ind._0_4_ = mac_frame.mhr.src_addr.u.group_addr;
          beacon_ind.pan_descriptor.coord_addr.addr_mode =
               *(ezb_addr_mode_t *)(mac_frame.mpl._0_4_ + 1);
          nwk_mm_asso_indication
                    ((dev->ctx).iface_id,(undefined1 *)((int)&poll_ind.device_address.u + 6));
          return;
        }
        if (uVar4 != 2) {
          return;
        }
        if (((undefined1  [116])dev->ctx & (undefined1  [116])0xffff00) !=
            (undefined1  [116])0x60200) {
          return;
        }
        if ((char)mac_frame.from == '\0') {
          return;
        }
        micro_timer_stop(&(dev->ctx).operation_timer);
        (dev->ctx).cur_op = '\0';
        if (*(char *)mac_frame.mpl._0_4_ == '\x02') {
          stack0xffffff9c = CONCAT13(uStack_62._1_1_,*(undefined3 *)(mac_frame.mpl._0_4_ + 1));
          if (mac_frame.mhr.dst_addr.u._4_1_ == '\x03') {
            *(undefined4 *)&(dev->pib).coord_extaddr.field_0 = mac_frame.mhr._8_4_;
            *(ezb_grpaddr_t *)((int)&(dev->pib).coord_extaddr.field_0 + 4) =
                 mac_frame.mhr.src_addr.u.group_addr;
          }
          mac_finish_association(dev,(mac_associate_cnf_t *)((int)&poll_ind.device_address.u + 6));
          mac_perform_next_op(dev);
          return;
        }
        uVar4 = __assert_func(0,0,0,0);
      }
      if (uVar4 != 7) {
        return;
      }
      op = MAC_OPERATION_TRANSMIT_BEACON;
      if ((dev->pib).beacon_payload_len == '\0') {
        return;
      }
_L0:
      mac_start_op(dev,op);
      return;
    }
    memcpy(auStack_70,(void *)((int)&mac_frame.mhr.dst_addr.u + 4),10);
    nwk_mm_poll_indication((dev->ctx).iface_id,auStack_70);
    pdVar2 = (dev->ctx).pend_q.list.next;
    do {
      if ((zmsg_queue_t *)pdVar2 == &(dev->ctx).pend_q) {
        return;
      }
      zmsg_get_footer(pdVar2,(undefined1 *)((int)&poll_ind.device_address.u + 6),10);
      if ((uint)(byte)mac_frame.mhr.dst_addr.u._4_1_ == (stack0xffffff9c & 0xff)) {
        if ((byte)mac_frame.mhr.dst_addr.u._4_1_ == 2) {
          uVar5._2_2_ = 0;
          uVar5._0_2_ = uStack_62;
          eVar7 = (ezb_grpaddr_t)(mac_frame.mhr._8_4_ & 0xffff);
        }
        else {
          eVar7 = (ezb_grpaddr_t)
                  ((uint)(ushort)beacon_ind.pan_descriptor.coord_addr._0_2_ << 0x10 |
                  (uint)beacon_ind._0_4_ >> 0x10);
          uVar5 = mac_frame.mhr.src_addr.u.group_addr;
          if (mac_frame.mhr._8_4_ != (beacon_ind._0_4_ << 0x10 | (uint)uStack_62)) goto _L0;
        }
        if (uVar5 == eVar7) {
          pdVar8 = pdVar2->prev;
          pdVar6 = pdVar2->next;
          pdVar6->prev = pdVar8;
          pdVar8->next = pdVar6;
          pdVar2->next = (dlist_node_s *)0x0;
          pdVar2->prev = (dlist_node_s *)0x0;
          zmsg_queue_enqueue(&(dev->ctx).itx_q,pdVar2);
          op = MAC_OPERATION_TRANSMIT_INDIRECT;
          goto _L0;
        }
      }
_L0:
      pdVar2 = pdVar2->next;
    } while( true );
  }
  if ((dev->ctx).state == '\x02') {
    return;
  }
  if ((uVar1 == '\x06') && ((char)mac_frame.from != '\0')) {
    if (mac_frame.mhr.dst_addr.u._4_1_ == '\x02') {
      mac_frame.mhr.src_addr.u._2_2_ = 0;
      mac_frame.mhr.src_addr.u._0_2_ = (dev->pib).coord_shortaddr;
      eVar7 = (ezb_grpaddr_t)(mac_frame.mhr._8_4_ & 0xffff);
    }
    else if ((mac_frame.mhr.dst_addr.u._4_1_ != '\x03') ||
            (eVar7 = *(ezb_grpaddr_t *)((int)&(dev->pib).coord_extaddr.field_0 + 4),
            mac_frame.mhr._8_4_ != *(int *)&(dev->pib).coord_extaddr.field_0)) goto _L0;
    if (mac_frame.mhr.src_addr.u.group_addr == eVar7) {
      micro_timer_stop(&(dev->ctx).operation_timer);
      (dev->ctx).cur_op = '\0';
      mac_report_poll_result(dev,'\0');
      mac_perform_next_op(dev);
    }
  }
_L0:
  nwk_mm_data_indication((dev->ctx).iface_id,&beacon_ind.beacon_payload);
  return;
}

