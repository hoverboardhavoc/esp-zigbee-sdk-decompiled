/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_data_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_data_req(mac_device *dev,mac_frame_t *frame)

{
  dlist_node_s *unaff_s0;
  _Bool _Var1;
  undefined3 extraout_var;
  dlist_node_s *pdVar2;
  dlist_node_s *pdVar3;
  undefined1 auStack_38 [4];
  ezb_address_t dst_addr;
  mac_poll_ind_t poll_ind;
  
  if (*(frame->mpl).buf == '\x04') {
    dst_addr.u._6_2_ = *(undefined2 *)&(frame->mhr).src_addr;
    nwk_mm_poll_indication((dev->ctx).iface_id,(undefined1 *)((int)&dst_addr.u + 6));
    for (unaff_s0 = (dev->ctx).pend_q.list.next; &(dev->ctx).pend_q != (zmsg_queue_t *)unaff_s0;
        unaff_s0 = unaff_s0->next) {
      zmsg_get_footer(unaff_s0,(ezb_address_t *)auStack_38,10);
      _Var1 = ezb_address_compare((ezb_address_t *)auStack_38,&(frame->mhr).src_addr);
      if (CONCAT31(extraout_var,_Var1) != 0) goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x409,"mac_handle_data_req"
                  ,"*cmd_ptr++ == 4U");
_L0:
    pdVar3 = unaff_s0->prev;
    pdVar2 = unaff_s0->next;
    pdVar2->prev = pdVar3;
    pdVar3->next = pdVar2;
    unaff_s0->next = (dlist_node_s *)0x0;
    unaff_s0->prev = (dlist_node_s *)0x0;
    zmsg_queue_enqueue(&(dev->ctx).itx_q,unaff_s0);
    mac_start_op(dev,MAC_OPERATION_TRANSMIT_INDIRECT);
  }
  return;
}

