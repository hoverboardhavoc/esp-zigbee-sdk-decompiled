/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_perform_next_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_perform_next_op(mac_device *dev)

{
  byte bVar1;
  ezb_panid_t eVar2;
  ezb_shortaddr_t eVar3;
  ushort uVar4;
  uint uVar5;
  char cVar6;
  ezb_radio_frame_t *tx_frame;
  zmsg_queue_t *pzVar7;
  zmsg_t *msg;
  int iVar8;
  ezb_err_t eVar9;
  uint8_t *__src;
  undefined2 uVar10;
  active_scan_callback p_Var11;
  uint8_t *puVar12;
  micro_timer_t *pmVar13;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if ((*(uint *)&(dev->ctx).field_0x70 & 1) == 0) {
    return;
  }
  if ((dev->ctx).cur_op == '\0') {
    uVar4 = (dev->ctx).pending_ops;
    if ((uVar4 & 0x40) == 0) {
      if ((uVar4 & 2) == 0) {
        if ((uVar4 & 4) == 0) {
          if ((uVar4 & 8) == 0) {
            if ((uVar4 & 0x80) == 0) {
              if ((uVar4 & 0x100) == 0) {
                if ((uVar4 & 0x20) == 0) {
                  uVar5 = 4;
                  if ((uVar4 & 0x10) == 0) {
                    if ((dev->ctx).cur_op != '\0') {
                      return;
                    }
                    if (-1 < *(int *)&(dev->pib).transaction_persistence_time << 0xe) {
                      mac_pal_sleep();
                      return;
                    }
                    mac_pal_receive((dev->ctx).phy_channel_page,(dev->ctx).phy_channel);
                    return;
                  }
                }
                else {
                  uVar5 = 5;
                }
              }
              else {
                uVar5 = 8;
              }
            }
            else {
              uVar5 = 7;
            }
          }
          else {
            uVar5 = 3;
          }
        }
        else {
          uVar5 = 2;
        }
      }
      else {
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 6;
    }
    pmVar13 = &(dev->ctx).operation_timer;
    (dev->ctx).pending_ops = uVar4 & ~(ushort)(1 << uVar5);
    (dev->ctx).cur_op = (uint8_t)uVar5;
    micro_timer_stop(pmVar13);
    if (uVar5 < 6) {
      if (uVar5 < 4) {
        if (uVar5 == 2) {
          (dev->ctx).state = '\x01';
          mac_do_ed_scan(dev);
          return;
        }
        if (uVar5 != 3) {
          (dev->ctx).state = '\x01';
          if (((*(uint *)&(dev->ctx).field_0x70 & 1) == 0) ||
             (eVar9 = mac_update_scan_channel(dev), eVar9 != 0)) {
            mac_pal_set_panid((dev->pib).panid);
            mac_pal_set_rx_when_idle(*(uint *)&(dev->pib).transaction_persistence_time >> 0x11 & 1);
            p_Var11 = (dev->ctx).field_7.active_scan_result_handler;
            (dev->ctx).state = '\0';
            (dev->ctx).cur_op = '\0';
            if (p_Var11 != (active_scan_callback)0x0) {
              (*p_Var11)((active_scan_result_t *)0x0,(dev->ctx).scan_user_ctx);
            }
            mac_perform_next_op(dev);
            return;
          }
          goto mac_do_transmit;
        }
        (dev->ctx).state = '\x02';
      }
    }
    else if (uVar5 == 6) {
      mac_pal_receive((dev->ctx).phy_channel_page,(dev->ctx).phy_channel);
      micro_timer_start(pmVar13,(((dev->pib).max_frame_total_wait_time + 0x3bf) / 0x3c0 + 1) *
                                0x3c00);
      return;
    }
    if ((*(uint *)&(dev->ctx).field_0x70 & 1) != 0) {
mac_do_transmit:
      tx_frame = (ezb_radio_frame_t *)mac_pal_get_tx_frame();
      tx_frame->channel = (dev->ctx).phy_channel;
      (tx_frame->info).tx.max_frame_retries = (dev->pib).max_frame_retries;
      (tx_frame->info).tx.max_csma_backoffs = (dev->pib).max_csma_backoffs;
      (tx_frame->info).tx.max_csma_be = (dev->pib).max_be;
      (tx_frame->info).tx.min_csma_be = (dev->pib).min_be;
      bVar1 = (dev->ctx).cur_op;
      puVar12 = (uint8_t *)(uint)bVar1;
      if (puVar12 == (uint8_t *)0x5) {
        mac_pal_set_rx_when_idle(1);
        puVar12 = (uint8_t *)0x3;
        uStack_24 = CONCAT31(uStack_24._1_3_,3);
        memcpy((void *)((int)&uStack_24 + 2),dev,8);
        uStack_18 = *(undefined4 *)&(dev->pib).coord_extaddr.field_0;
        uVar4 = (dev->pib).coord_shortaddr;
        uStack_1c._0_3_ = CONCAT12(3,(undefined2)uStack_1c);
        eVar2 = (dev->pib).panid;
        uStack_28 = CONCAT22(eVar2,eVar2);
        if (uVar4 < 0xfffe) {
          uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
          uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
          uStack_18 = CONCAT22(uStack_18._2_2_,uVar4);
        }
        uVar4 = (dev->pib).short_address;
        if (uVar4 < 0xfffe) {
          uStack_24 = CONCAT31(uStack_24._1_3_,2);
          uStack_24 = CONCAT22(uVar4,(undefined2)uStack_24);
        }
        cVar6 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,3,4);
        tx_frame->length = cVar6 + '\x02';
        goto _L0;
      }
      if ((uint8_t *)0x5 < puVar12) goto _L0;
      if (puVar12 == (uint8_t *)0x3) {
        uStack_24 = CONCAT31(uStack_24._1_3_,bVar1);
        memcpy((void *)((int)&uStack_24 + 2),dev,8);
        uStack_18 = *(undefined4 *)&(dev->pib).coord_extaddr.field_0;
        uVar4 = (dev->pib).coord_shortaddr;
        uStack_1c._0_3_ = CONCAT12(bVar1,(undefined2)uStack_1c);
        uStack_28 = CONCAT22((dev->pib).panid,0xffff);
        if (uVar4 < 0xfffe) {
          uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
          uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
          uStack_18 = CONCAT22(uStack_18._2_2_,uVar4);
        }
        cVar6 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,3,1);
        tx_frame->length = cVar6 + '\x02';
        (dev->pib).dsn = (dev->pib).dsn + '\x01';
        mac_frame_set_seq_num(tx_frame);
        puVar12 = tx_frame->psdu;
        iVar8 = mac_frame_find_payload_index(tx_frame);
        puVar12 = puVar12 + iVar8;
        puVar12[1] = (dev->ctx).mac_cap_info;
        tx_frame->length = tx_frame->length + '\x01';
        goto _L0;
      }
      if (puVar12 == (uint8_t *)0x4) {
        pzVar7 = &(dev->ctx).tx_q;
        goto _L0;
      }
      if (puVar12 == (uint8_t *)0x1) {
        uStack_1c = 0x20000;
        uStack_18 = 0xffff;
        uStack_28 = 0xffffffff;
        uStack_24 = 0;
        uStack_20 = 0;
        cVar6 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,7);
        tx_frame->length = cVar6 + '\x02';
        (dev->pib).dsn = (dev->pib).dsn + '\x01';
        mac_frame_set_seq_num(tx_frame);
        mac_pal_set_panid(0xffff);
        mac_pal_set_rx_when_idle(1);
        tx_frame->channel = (dev->ctx).scan_channel;
        goto _L0;
      }
_L0:
      do {
        __assert_func(0,0,0,0);
_L0:
        if (puVar12 == (uint8_t *)0x7) {
          memset((void *)((int)&uStack_24 + 1),0,0x13);
          uStack_24 = CONCAT31(uStack_24._1_3_,2);
          uStack_24 = CONCAT22((dev->pib).short_address,(undefined2)uStack_24);
          uStack_28 = CONCAT22(0xffff,(dev->pib).panid);
          cVar6 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,0,0);
          tx_frame->length = cVar6 + '\x02';
          (dev->pib).bsn = (dev->pib).bsn + '\x01';
          mac_frame_set_seq_num(tx_frame);
          puVar12 = tx_frame->psdu;
          iVar8 = mac_frame_find_payload_index(tx_frame);
          uVar4 = *(ushort *)&(dev->pib).field_0x2a;
          eVar3 = (dev->pib).coord_shortaddr;
          puVar12 = puVar12 + iVar8;
          if ((eVar3 == 0xffff) || (uVar10 = 0x4fff, (dev->pib).short_address != eVar3)) {
            uVar10 = 0xfff;
          }
          *puVar12 = (uint8_t)uVar10;
          puVar12[2] = '\0';
          puVar12[3] = '\0';
          puVar12[1] = (byte)(((uVar4 & 1) << 0xf) >> 8) | (byte)((ushort)uVar10 >> 8);
          uVar5 = 0;
          tx_frame->length = tx_frame->length + '\x04';
          __src = (dev->pib).beacon_payload;
          if ((__src != (uint8_t *)0x0) && (uVar5 = (uint)(dev->pib).beacon_payload_len, uVar5 != 0)
             ) {
            memcpy(puVar12 + 4,__src,uVar5);
          }
          puVar12 = (uint8_t *)(uVar5 + tx_frame->length);
          tx_frame->length = (uint8_t)puVar12;
        }
        else {
          pzVar7 = &(dev->ctx).itx_q;
          if (puVar12 != (uint8_t *)0x8) goto _L0;
_L0:
          msg = (zmsg_t *)zmsg_queue_get_head(pzVar7);
          if (msg == (zmsg_t *)0x0) goto _L0;
          txframe_from_zmsg(msg,tx_frame);
_L0:
          (dev->pib).dsn = (dev->pib).dsn + '\x01';
          mac_frame_set_seq_num(tx_frame);
        }
_L0:
        iVar8 = mac_pal_transmit();
        if (iVar8 == 0) {
          return;
        }
      } while( true );
    }
  }
  return;
}

