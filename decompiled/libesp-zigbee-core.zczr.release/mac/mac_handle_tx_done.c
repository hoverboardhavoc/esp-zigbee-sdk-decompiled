/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_handle_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_tx_done(mac_device *dev,zmsg_queue_t *q,ezb_err_t tx_error,_Bool is_indirect)

{
  void *__s;
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined3 in_register_00002035;
  undefined1 uStack_71;
  void *pvStack_70;
  uint8_t mhr_len;
  ezb_radio_frame_t frame;
  mac_comm_status_ind_t comm_ind;
  undefined1 auStack_3c [4];
  mac_header_t mhr;
  
  iVar2 = zmsg_queue_get_head(q);
  if (iVar2 != 0) {
    uStack_71 = 0;
    zmsg_queue_dequeue(q,iVar2);
    if (CONCAT31(in_register_00002035,is_indirect) != 0) {
      zmsg_remove_footer(iVar2,10);
    }
    __s = (void *)((int)&frame.info + 0xc);
    memset(__s,0,0x1a);
    frame.psdu = (uint8_t *)0x0;
    frame.length = '\0';
    frame.channel = '\0';
    frame._6_2_ = 0;
    frame.info.tx.timestamp._0_4_ = 0;
    frame.info.tx.timestamp._4_4_ = 0;
    frame.info._8_4_ = 0;
    pvStack_70 = __s;
    uVar1 = zmsg_read_bytes(iVar2,0,0x1a,__s);
    frame.psdu = (uint8_t *)CONCAT31(frame.psdu._1_3_,uVar1);
    iVar3 = mac_frame_parse_header(&stack0xffffff90,auStack_3c,&uStack_71);
    if (iVar3 == 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      zmsg_remove_header(iVar2,uStack_71);
      comm_ind.addresses.source.addr_mode = (ezb_addr_mode_t)tx_error;
      if (mhr.src_panid._1_1_ == '\x02') {
        memcpy(__s,(void *)((int)&mhr.dst_addr.u + 4),10);
        memcpy((void *)((int)&comm_ind.addresses.source.u + 4),auStack_3c,10);
        comm_ind.addresses.destination.u._4_2_ = mhr.src_addr.u._4_2_;
        comm_ind.addresses.destination.u._6_1_ = comm_ind.addresses.source.addr_mode;
        nwk_mm_comm_status_indication((dev->ctx).iface_id,__s);
        zmsg_free(iVar2);
        return;
      }
    } while ((mhr.dst_panid & 7) != 1);
    comm_ind.addresses.source._1_1_ = comm_ind.addresses.source._1_1_ & 0xfe | is_indirect;
    frame.info._12_4_ = iVar2;
    nwk_mm_data_confirm((dev->ctx).iface_id,__s);
  }
  return;
}

