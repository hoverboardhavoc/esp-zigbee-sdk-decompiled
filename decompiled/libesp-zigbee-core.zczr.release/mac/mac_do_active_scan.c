/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_do_active_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_do_active_scan(mac_device *dev)

{
  byte bVar1;
  ushort uVar2;
  ezb_shortaddr_t eVar3;
  char cVar4;
  ezb_radio_frame_t *tx_frame;
  zmsg_queue_t *pzVar5;
  zmsg_t *msg;
  int iVar6;
  ezb_err_t eVar7;
  uint8_t *__src;
  undefined2 uVar8;
  active_scan_callback p_Var9;
  uint8_t *puVar10;
  uint __n;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (((*(uint *)&(dev->ctx).field_0x70 & 1) == 0) ||
     (eVar7 = mac_update_scan_channel(dev), eVar7 != 0)) {
    mac_pal_set_panid((dev->pib).panid);
    mac_pal_set_rx_when_idle(*(uint *)&(dev->pib).transaction_persistence_time >> 0x11 & 1);
    p_Var9 = (dev->ctx).field_7.active_scan_result_handler;
    (dev->ctx).state = '\0';
    (dev->ctx).cur_op = '\0';
    if (p_Var9 != (active_scan_callback)0x0) {
      (*p_Var9)((active_scan_result_t *)0x0,(dev->ctx).scan_user_ctx);
    }
    mac_perform_next_op(dev);
    return;
  }
  tx_frame = (ezb_radio_frame_t *)mac_pal_get_tx_frame();
  tx_frame->channel = (dev->ctx).phy_channel;
  (tx_frame->info).tx.max_frame_retries = (dev->pib).max_frame_retries;
  (tx_frame->info).tx.max_csma_backoffs = (dev->pib).max_csma_backoffs;
  (tx_frame->info).tx.max_csma_be = (dev->pib).max_be;
  (tx_frame->info).tx.min_csma_be = (dev->pib).min_be;
  bVar1 = (dev->ctx).cur_op;
  puVar10 = (uint8_t *)(uint)bVar1;
  if (puVar10 == (uint8_t *)0x5) {
    mac_pal_set_rx_when_idle(1);
    puVar10 = (uint8_t *)0x3;
    uStack_24 = CONCAT31(uStack_24._1_3_,3);
    memcpy((void *)((int)&uStack_24 + 2),dev,8);
    uStack_18 = *(undefined4 *)&(dev->pib).coord_extaddr.field_0;
    uVar2 = (dev->pib).coord_shortaddr;
    uStack_1c._0_3_ = CONCAT12(3,(undefined2)uStack_1c);
    uStack_14 = *(undefined4 *)((int)&(dev->pib).coord_extaddr.field_0 + 4);
    uStack_28 = CONCAT22((dev->pib).panid,0xffff);
    if (uVar2 < 0xfffe) {
      uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
      uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
      uStack_18 = CONCAT22(uStack_18._2_2_,uVar2);
    }
    uVar2 = (dev->pib).short_address;
    if (uVar2 < 0xfffe) {
      uStack_24 = CONCAT31(uStack_24._1_3_,2);
      uStack_24 = CONCAT22(uVar2,(undefined2)uStack_24);
    }
    cVar4 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,3,4);
    tx_frame->length = cVar4 + '\x02';
    goto _L0;
  }
  if ((uint8_t *)0x5 < puVar10) goto _L0;
  if (puVar10 == (uint8_t *)0x3) {
    uStack_24 = CONCAT31(uStack_24._1_3_,bVar1);
    memcpy((void *)((int)&uStack_24 + 2),dev,8);
    uStack_18 = *(undefined4 *)&(dev->pib).coord_extaddr.field_0;
    uVar2 = (dev->pib).coord_shortaddr;
    uStack_1c._0_3_ = CONCAT12(bVar1,(undefined2)uStack_1c);
    uStack_14 = *(undefined4 *)((int)&(dev->pib).coord_extaddr.field_0 + 4);
    uStack_28 = CONCAT22((dev->pib).panid,0xffff);
    if (uVar2 < 0xfffe) {
      uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
      uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
      uStack_18 = CONCAT22(uStack_18._2_2_,uVar2);
    }
    cVar4 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,3,1);
    tx_frame->length = cVar4 + '\x02';
    (dev->pib).dsn = (dev->pib).dsn + '\x01';
    mac_frame_set_seq_num(tx_frame);
    puVar10 = tx_frame->psdu;
    iVar6 = mac_frame_find_payload_index(tx_frame);
    puVar10 = puVar10 + iVar6;
    puVar10[1] = (dev->ctx).mac_cap_info;
    tx_frame->length = tx_frame->length + '\x01';
    goto _L0;
  }
  if (puVar10 == (uint8_t *)0x4) {
    pzVar5 = &(dev->ctx).tx_q;
    goto _L0;
  }
  if (puVar10 == (uint8_t *)0x1) {
    uStack_1c = 0x20000;
    uStack_18 = 0xffff;
    uStack_28 = 0xffffffff;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_14 = 0;
    cVar4 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,7);
    tx_frame->length = cVar4 + '\x02';
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
    if (puVar10 == (uint8_t *)0x7) {
      memset((void *)((int)&uStack_24 + 1),0,0x13);
      uStack_24 = CONCAT31(uStack_24._1_3_,2);
      uStack_24 = CONCAT22((dev->pib).short_address,(undefined2)uStack_24);
      uStack_28 = CONCAT22(0xffff,(dev->pib).panid);
      cVar4 = mac_frame_write_hdr(tx_frame->psdu,&uStack_24,&uStack_28,0,0,0);
      tx_frame->length = cVar4 + '\x02';
      (dev->pib).bsn = (dev->pib).bsn + '\x01';
      mac_frame_set_seq_num(tx_frame);
      puVar10 = tx_frame->psdu;
      iVar6 = mac_frame_find_payload_index(tx_frame);
      uVar2 = *(ushort *)&(dev->pib).field_0x2a;
      eVar3 = (dev->pib).coord_shortaddr;
      puVar10 = puVar10 + iVar6;
      if ((eVar3 == 0xffff) || (uVar8 = 0x4fff, (dev->pib).short_address != eVar3)) {
        uVar8 = 0xfff;
      }
      *puVar10 = (uint8_t)uVar8;
      puVar10[2] = '\0';
      puVar10[3] = '\0';
      puVar10[1] = (byte)(((uVar2 & 1) << 0xf) >> 8) | (byte)((ushort)uVar8 >> 8);
      __n = 0;
      tx_frame->length = tx_frame->length + '\x04';
      __src = (dev->pib).beacon_payload;
      if ((__src != (uint8_t *)0x0) && (__n = (uint)(dev->pib).beacon_payload_len, __n != 0)) {
        memcpy(puVar10 + 4,__src,__n);
      }
      puVar10 = (uint8_t *)(__n + tx_frame->length);
      tx_frame->length = (uint8_t)puVar10;
    }
    else {
      pzVar5 = &(dev->ctx).itx_q;
      if (puVar10 != (uint8_t *)0x8) goto _L0;
_L0:
      msg = (zmsg_t *)zmsg_queue_get_head(pzVar5);
      if (msg == (zmsg_t *)0x0) goto _L0;
      txframe_from_zmsg(msg,tx_frame);
_L0:
      (dev->pib).dsn = (dev->pib).dsn + '\x01';
      mac_frame_set_seq_num(tx_frame);
    }
_L0:
    iVar6 = mac_pal_transmit();
    if (iVar6 == 0) {
      return;
    }
  } while( true );
}

