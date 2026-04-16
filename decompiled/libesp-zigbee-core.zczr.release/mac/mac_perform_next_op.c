/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  ezb_shortaddr_t eVar2;
  ushort uVar3;
  uint uVar4;
  char cVar5;
  ezb_radio_frame_t *tx_frame;
  zmsg_queue_t *pzVar6;
  zmsg_t *msg;
  int iVar7;
  ezb_err_t eVar8;
  uint8_t *__src;
  undefined2 uVar9;
  active_scan_callback p_Var10;
  uint8_t *puVar11;
  micro_timer_t *pmVar12;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if ((*(uint *)&(dev->ctx).field_0x70 & 1) == 0) {
    return;
  }
  if ((dev->ctx).cur_op == '\0') {
    uVar3 = (dev->ctx).pending_ops;
    if ((uVar3 & 0x40) == 0) {
      if ((uVar3 & 2) == 0) {
        if ((uVar3 & 4) == 0) {
          if ((uVar3 & 8) == 0) {
            if ((uVar3 & 0x80) == 0) {
              if ((uVar3 & 0x100) == 0) {
                if ((uVar3 & 0x20) == 0) {
                  uVar4 = 4;
                  if ((uVar3 & 0x10) == 0) {
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
                  uVar4 = 5;
                }
              }
              else {
                uVar4 = 8;
              }
            }
            else {
              uVar4 = 7;
            }
          }
          else {
            uVar4 = 3;
          }
        }
        else {
          uVar4 = 2;
        }
      }
      else {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 6;
    }
    pmVar12 = &(dev->ctx).operation_timer;
    (dev->ctx).pending_ops = uVar3 & ~(ushort)(1 << uVar4);
    (dev->ctx).cur_op = (uint8_t)uVar4;
    micro_timer_stop(pmVar12);
    if (uVar4 < 6) {
      if (uVar4 < 4) {
        if (uVar4 == 2) {
          (dev->ctx).state = '\x01';
          mac_do_ed_scan(dev);
          return;
        }
        if (uVar4 != 3) {
          (dev->ctx).state = '\x01';
          if (((*(uint *)&(dev->ctx).field_0x70 & 1) == 0) ||
             (eVar8 = mac_update_scan_channel(dev), eVar8 != 0)) {
            mac_pal_set_panid((dev->pib).panid);
            mac_pal_set_rx_when_idle(*(uint *)&(dev->pib).transaction_persistence_time >> 0x11 & 1);
            p_Var10 = (dev->ctx).field_7.active_scan_result_handler;
            (dev->ctx).state = '\0';
            (dev->ctx).cur_op = '\0';
            if (p_Var10 != (active_scan_callback)0x0) {
              (*p_Var10)((active_scan_result_t *)0x0,(dev->ctx).scan_user_ctx);
            }
            mac_perform_next_op(dev);
            return;
          }
          goto mac_do_transmit;
        }
        (dev->ctx).state = '\x02';
      }
    }
    else if (uVar4 == 6) {
      mac_pal_receive((dev->ctx).phy_channel_page,(dev->ctx).phy_channel);
      micro_timer_start(pmVar12,(((dev->pib).max_frame_total_wait_time + 0x3bf) / 0x3c0 + 1) *
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
      puVar11 = (uint8_t *)(uint)bVar1;
      if (puVar11 == (uint8_t *)0x5) {
        mac_pal_set_rx_when_idle(1);
        puVar11 = (uint8_t *)0x3;
        uStack_24 = CONCAT31(uStack_24._1_3_,3);
        memcpy((void *)((int)&uStack_24 + 2),dev,8);
        uStack_18 = *(undefined4 *)&(dev->pib).coord_extaddr.field_0;
        uVar3 = (dev->pib).coord_shortaddr;
        uStack_1c._0_3_ = CONCAT12(3,(undefined2)uStack_1c);
        uStack_28 = CONCAT22((dev->pib).panid,0xffff);
        if (uVar3 < 0xfffe) {
          uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
          uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
          uStack_18 = CONCAT22(uStack_18._2_2_,uVar3);
        }
        uVar3 = (dev->pib).short_address;
        if (uVar3 < 0xfffe) {
          uStack_24 = CONCAT31(uStack_24._1_3_,2);
          uStack_24 = CONCAT22(uVar3,(undefined2)uStack_24);
        }
        cVar5 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,3,4);
        tx_frame->length = cVar5 + '\x02';
        goto _L0;
      }
      if ((uint8_t *)0x5 < puVar11) goto _L0;
      if (puVar11 == (uint8_t *)0x3) {
        uStack_24 = CONCAT31(uStack_24._1_3_,bVar1);
        memcpy((void *)((int)&uStack_24 + 2),dev,8);
        uStack_18 = *(undefined4 *)&(dev->pib).coord_extaddr.field_0;
        uVar3 = (dev->pib).coord_shortaddr;
        uStack_1c._0_3_ = CONCAT12(bVar1,(undefined2)uStack_1c);
        uStack_28 = CONCAT22((dev->pib).panid,0xffff);
        if (uVar3 < 0xfffe) {
          uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
          uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
          uStack_18 = CONCAT22(uStack_18._2_2_,uVar3);
        }
        cVar5 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,3,1);
        tx_frame->length = cVar5 + '\x02';
        (dev->pib).dsn = (dev->pib).dsn + '\x01';
        mac_frame_set_seq_num(tx_frame);
        puVar11 = tx_frame->psdu;
        iVar7 = mac_frame_find_payload_index(tx_frame);
        puVar11 = puVar11 + iVar7;
        puVar11[1] = (dev->ctx).mac_cap_info;
        tx_frame->length = tx_frame->length + '\x01';
        goto _L0;
      }
      if (puVar11 == (uint8_t *)0x4) {
        pzVar6 = &(dev->ctx).tx_q;
        goto _L0;
      }
      if (puVar11 == (uint8_t *)0x1) {
        uStack_1c = 0x20000;
        uStack_18 = 0xffff;
        uStack_28 = 0xffffffff;
        uStack_24 = 0;
        uStack_20 = 0;
        cVar5 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,7);
        tx_frame->length = cVar5 + '\x02';
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
        if (puVar11 == (uint8_t *)0x7) {
          memset((void *)((int)&uStack_24 + 1),0,0x13);
          uStack_24 = CONCAT31(uStack_24._1_3_,2);
          uStack_24 = CONCAT22((dev->pib).short_address,(undefined2)uStack_24);
          uStack_28 = CONCAT22(0xffff,(dev->pib).panid);
          cVar5 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,0,0);
          tx_frame->length = cVar5 + '\x02';
          (dev->pib).bsn = (dev->pib).bsn + '\x01';
          mac_frame_set_seq_num(tx_frame);
          puVar11 = tx_frame->psdu;
          iVar7 = mac_frame_find_payload_index(tx_frame);
          uVar3 = *(ushort *)&(dev->pib).field_0x2a;
          eVar2 = (dev->pib).coord_shortaddr;
          puVar11 = puVar11 + iVar7;
          if ((eVar2 == 0xffff) || (uVar9 = 0x4fff, (dev->pib).short_address != eVar2)) {
            uVar9 = 0xfff;
          }
          *puVar11 = (uint8_t)uVar9;
          puVar11[2] = '\0';
          puVar11[3] = '\0';
          puVar11[1] = (byte)(((uVar3 & 1) << 0xf) >> 8) | (byte)((ushort)uVar9 >> 8);
          uVar4 = 0;
          tx_frame->length = tx_frame->length + '\x04';
          __src = (dev->pib).beacon_payload;
          if ((__src != (uint8_t *)0x0) && (uVar4 = (uint)(dev->pib).beacon_payload_len, uVar4 != 0)
             ) {
            memcpy(puVar11 + 4,__src,uVar4);
          }
          puVar11 = (uint8_t *)(uVar4 + tx_frame->length);
          tx_frame->length = (uint8_t)puVar11;
        }
        else {
          pzVar6 = &(dev->ctx).itx_q;
          if (puVar11 != (uint8_t *)0x8) goto _L0;
_L0:
          msg = (zmsg_t *)zmsg_queue_get_head(pzVar6);
          if (msg == (zmsg_t *)0x0) goto _L0;
          txframe_from_zmsg(msg,tx_frame);
_L0:
          (dev->pib).dsn = (dev->pib).dsn + '\x01';
          mac_frame_set_seq_num(tx_frame);
        }
_L0:
        iVar7 = mac_pal_transmit();
        if (iVar7 == 0) {
          return;
        }
      } while( true );
    }
  }
  return;
}

