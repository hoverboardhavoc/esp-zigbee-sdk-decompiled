/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_timer_func_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_timer_func_wrapper(void *param)

{
  ushort uVar1;
  ezb_panid_t eVar2;
  char cVar3;
  ezb_radio_frame_t *tx_frame;
  ezb_err_t eVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *extraout_a1;
  undefined2 uVar9;
  uint8_t *puVar10;
  mac_device *dev;
  zmsg_t *pzVar11;
  ezb_panid_t eStack_50;
  undefined2 uStack_4e;
  undefined1 auStack_4c [36];
  undefined4 uStack_28;
  
  cVar3 = *(char *)((int)param + 0x2e);
  if (cVar3 == '\x03') {
    *(undefined1 *)((int)param + 0x2e) = 0;
    mac_start_op((mac_device *)param,MAC_OPERATION_TRANSMIT_POLL);
  }
  else {
    if (cVar3 != '\x06') {
      if (cVar3 != '\x01') {
        puVar5 = (undefined4 *)__assert_func(0,0,0,0);
        dev = (mac_device *)*puVar5;
        if ((((*(uint *)&(dev->ctx).field_0x70 & 1) != 0) && (extraout_a1 != (undefined4 *)0x0)) &&
           (pzVar11 = (zmsg_t *)*extraout_a1, pzVar11 != (zmsg_t *)0x0)) {
          eVar2 = (dev->pib).panid;
          memset(auStack_4c,0,0x1c);
          uStack_4e = *(undefined2 *)(extraout_a1 + 6);
          eStack_50 = eVar2;
          uVar6 = mac_frame_write_hdr(auStack_4c,extraout_a1 + 1,&eStack_50,0,1,0);
          iVar7 = zmsg_prepend_bytes(pzVar11,uVar6,auStack_4c);
          if ((iVar7 == 0) && (uVar8 = zmsg_get_length(pzVar11), uVar8 < 0x7e)) {
            if ((*(byte *)((int)extraout_a1 + 0x1a) & 2) == 0) {
              zmsg_queue_enqueue(&(dev->ctx).tx_q,pzVar11);
              if (((dev->ctx).cur_op != '\x04') && (((dev->ctx).pending_ops & 0x10) == 0)) {
                mac_start_op(dev,MAC_OPERATION_TRANSMIT_DATA_DIRECT);
              }
            }
            else {
              mac_indirect_transmit(dev,(ezb_address_t *)((int)extraout_a1 + 0xe),pzVar11);
            }
          }
        }
        return;
      }
      if (((*(uint *)((int)param + 0x9c) & 1) == 0) ||
         (eVar4 = mac_update_scan_channel((mac_device *)param), eVar4 != 0)) {
        mac_pal_set_panid(*(undefined2 *)((int)param + 10));
        mac_pal_set_rx_when_idle(*(uint *)((int)param + 0x28) >> 0x11 & 1);
        *(undefined1 *)((int)param + 0x2d) = 0;
        *(undefined1 *)((int)param + 0x2e) = 0;
        if (*(code **)((int)param + 0x38) != (code *)0x0) {
          (**(code **)((int)param + 0x38))(0,*(undefined4 *)((int)param + 0x3c));
        }
        mac_perform_next_op((mac_device *)param);
        return;
      }
      tx_frame = (ezb_radio_frame_t *)mac_pal_get_tx_frame();
      tx_frame->channel = *(uint8_t *)((int)param + 0x41);
      (tx_frame->info).tx.max_frame_retries = *(uint8_t *)((int)param + 0x1e);
      (tx_frame->info).tx.max_csma_backoffs = *(uint8_t *)((int)param + 0x22);
      (tx_frame->info).tx.max_csma_be = *(uint8_t *)((int)param + 0x21);
      (tx_frame->info).tx.min_csma_be = *(uint8_t *)((int)param + 0x20);
      puVar10 = (uint8_t *)(uint)*(byte *)((int)param + 0x2e);
      if (puVar10 == (uint8_t *)0x5) {
        mac_pal_set_rx_when_idle(1);
        puVar10 = (uint8_t *)0x3;
        memcpy(&stack0xffffffde,param,8);
        uStack_28 = CONCAT22(*(undefined2 *)((int)param + 10),*(undefined2 *)((int)param + 10));
        cVar3 = mac_frame_write_hdr(tx_frame->psdu,&stack0xffffffdc,&uStack_28,0,3,4);
        tx_frame->length = cVar3 + '\x02';
        goto _L0;
      }
      if ((uint8_t *)0x5 < puVar10) goto _L0;
      if (puVar10 == (uint8_t *)0x3) {
        memcpy(&stack0xffffffde,param,8);
        uStack_28 = CONCAT22(*(undefined2 *)((int)param + 10),0xffff);
        cVar3 = mac_frame_write_hdr(tx_frame->psdu,&stack0xffffffdc,&uStack_28,0,3,1);
        tx_frame->length = cVar3 + '\x02';
        *(char *)((int)param + 0xc) = *(char *)((int)param + 0xc) + '\x01';
        mac_frame_set_seq_num(tx_frame);
        puVar10 = tx_frame->psdu;
        iVar7 = mac_frame_find_payload_index(tx_frame);
        puVar10 = puVar10 + iVar7;
        puVar10[1] = *(uint8_t *)((int)param + 0x40);
        tx_frame->length = tx_frame->length + '\x01';
        goto _L0;
      }
      if (puVar10 == (uint8_t *)0x4) {
        iVar7 = (int)param + 0x48;
        goto _L0;
      }
      if (puVar10 == (uint8_t *)0x1) {
        uStack_28 = 0xffffffff;
        cVar3 = mac_frame_write_hdr(tx_frame->psdu,&stack0xffffffdc,&uStack_28,0,7);
        tx_frame->length = cVar3 + '\x02';
        *(char *)((int)param + 0xc) = *(char *)((int)param + 0xc) + '\x01';
        mac_frame_set_seq_num(tx_frame);
        mac_pal_set_panid(0xffff);
        mac_pal_set_rx_when_idle(1);
        tx_frame->channel = *(uint8_t *)((int)param + 0x32);
        goto _L0;
      }
_L0:
      do {
        __assert_func(0,0,0,0);
_L0:
        if (puVar10 == (uint8_t *)0x7) {
          memset(&stack0xffffffdd,0,0x13);
          uStack_28 = CONCAT22(0xffff,*(undefined2 *)((int)param + 10));
          cVar3 = mac_frame_write_hdr(tx_frame->psdu,&stack0xffffffdc,&uStack_28,0,0,0);
          tx_frame->length = cVar3 + '\x02';
          *(char *)((int)param + 0xd) = *(char *)((int)param + 0xd) + '\x01';
          mac_frame_set_seq_num(tx_frame);
          puVar10 = tx_frame->psdu;
          iVar7 = mac_frame_find_payload_index(tx_frame);
          uVar1 = *(ushort *)((int)param + 0x2a);
          puVar10 = puVar10 + iVar7;
          if ((*(short *)((int)param + 0xe) == -1) ||
             (uVar9 = 0x4fff, *(short *)((int)param + 8) != *(short *)((int)param + 0xe))) {
            uVar9 = 0xfff;
          }
          *puVar10 = (uint8_t)uVar9;
          puVar10[2] = '\0';
          puVar10[3] = '\0';
          puVar10[1] = (byte)(((uVar1 & 1) << 0xf) >> 8) | (byte)((ushort)uVar9 >> 8);
          uVar8 = 0;
          tx_frame->length = tx_frame->length + '\x04';
          if ((*(void **)((int)param + 0x24) != (void *)0x0) &&
             (uVar8 = (uint)*(byte *)((int)param + 0x23), uVar8 != 0)) {
            memcpy(puVar10 + 4,*(void **)((int)param + 0x24),uVar8);
          }
          puVar10 = (uint8_t *)(uVar8 + tx_frame->length);
          tx_frame->length = (uint8_t)puVar10;
        }
        else {
          iVar7 = (int)param + 0x54;
          if (puVar10 != (uint8_t *)0x8) goto _L0;
_L0:
          pzVar11 = (zmsg_t *)zmsg_queue_get_head(iVar7);
          if (pzVar11 == (zmsg_t *)0x0) goto _L0;
          txframe_from_zmsg(pzVar11,tx_frame);
_L0:
          *(char *)((int)param + 0xc) = *(char *)((int)param + 0xc) + '\x01';
          mac_frame_set_seq_num(tx_frame);
        }
_L0:
        iVar7 = mac_pal_transmit();
        if (iVar7 == 0) {
          return;
        }
      } while( true );
    }
    *(undefined1 *)((int)param + 0x2e) = 0;
    mac_report_poll_result((mac_device *)param,0xeb);
  }
  mac_perform_next_op((mac_device *)param);
  return;
}

