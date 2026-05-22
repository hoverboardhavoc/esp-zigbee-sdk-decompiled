/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_tx_done(mac_device *dev,zmsg_queue_t *q,ezb_err_t tx_error,_Bool is_indirect)

{
  zmsg_queue_t *pzVar1;
  zmsg_t *msg;
  ezb_err_t eVar2;
  mac_device *dev_00;
  int iVar3;
  char *extraout_a1;
  undefined3 in_register_00002035;
  zmsg_t *pzStack_58;
  mac_comm_status_ind_t comm_ind;
  undefined1 auStack_3c [3];
  uint8_t mhr_len;
  mac_header_t mhr;
  
  msg = (zmsg_t *)zmsg_queue_get_head(q);
  if (msg != (zmsg_t *)0x0) {
    comm_ind._23_1_ = 0;
    zmsg_queue_dequeue(q,msg);
    if (CONCAT31(in_register_00002035,is_indirect) != 0) {
      zmsg_remove_footer(msg,10);
    }
    eVar2 = parse_mhr_from_msg(msg,(mac_header_t *)auStack_3c,&comm_ind.field_0x17);
    if (eVar2 == 0) {
      zmsg_remove_header(msg,comm_ind._23_1_);
      if (mhr.src_panid._1_1_ != '\x02') {
        if ((mhr.dst_panid & 7) == 1) {
          comm_ind.addresses.source._1_1_ = comm_ind.addresses.source._1_1_ & 0xfe | is_indirect;
          comm_ind.addresses.source.addr_mode = (ezb_addr_mode_t)tx_error;
          pzStack_58 = msg;
          nwk_mm_data_confirm((dev->ctx).iface_id,&pzStack_58);
          return;
        }
        dev_00 = (mac_device *)
                 __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x4ed,
                               "mac_handle_tx_done",
                               "mac_fcf_get_frame_type(mhr.fcf) == MAC_FRAME_DATA");
        if (*extraout_a1 == '\0') {
          pzVar1 = &(dev_00->ctx).tx_q;
          while (iVar3 = zmsg_queue_get_head(pzVar1), iVar3 != 0) {
            mac_handle_tx_done(dev_00,pzVar1,0xda,false);
          }
          pzVar1 = &(dev_00->ctx).itx_q;
          while (iVar3 = zmsg_queue_get_head(pzVar1), iVar3 != 0) {
            mac_handle_tx_done(dev_00,pzVar1,0xda,true);
          }
          pzVar1 = &(dev_00->ctx).pend_q;
          while (iVar3 = zmsg_queue_get_head(pzVar1), iVar3 != 0) {
            mac_handle_tx_done(dev_00,pzVar1,0xda,true);
          }
          micro_timer_stop(&(dev_00->ctx).transaction_timer);
        }
        return;
      }
    }
    else {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x4dd,
                    "mac_handle_tx_done","(parse_mhr_from_msg(msg, &mhr, &mhr_len)) == 0");
    }
    comm_ind.addresses.source.addr_mode = mhr.src_addr.addr_mode;
    comm_ind.addresses.source._1_1_ = mhr.src_addr._1_1_;
    comm_ind.addresses.source.u.short_addr = mhr.src_addr.u.short_addr;
    comm_ind.addresses.source.u.group_addr.bcast = mhr.src_addr.u.group_addr.bcast;
    comm_ind.addresses.source.u._4_2_ = auStack_3c._0_2_;
    comm_ind.addresses.source.u._6_2_ = stack0xffffffc6;
    comm_ind.addresses.destination.addr_mode = mhr.dst_addr.addr_mode;
    comm_ind.addresses.destination._1_1_ = mhr.dst_addr._1_1_;
    comm_ind.addresses.destination.u.short_addr = mhr.dst_addr.u.short_addr;
    comm_ind.addresses.destination.u.group_addr.bcast = mhr.dst_addr.u.group_addr.bcast;
    comm_ind.addresses.destination.u._4_2_ = mhr.src_addr.u._4_2_;
    comm_ind.addresses.destination.u._6_1_ = (ezb_addr_mode_t)tx_error;
    nwk_mm_comm_status_indication((dev->ctx).iface_id,&pzStack_58);
    zmsg_free(msg);
  }
  return;
}

