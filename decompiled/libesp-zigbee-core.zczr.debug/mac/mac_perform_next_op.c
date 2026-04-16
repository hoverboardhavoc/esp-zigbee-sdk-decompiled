/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_perform_next_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_perform_next_op(mac_device *dev)

{
  mac_operation_t next_op;
  mac_operation_t op;
  _Bool _Var1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  
  _Var1 = mac_is_enabled(dev);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    return;
  }
  if ((dev->ctx).cur_op != '\0') {
    return;
  }
  _Var1 = mac_is_op_pending(dev,MAC_OPERATION_WAITING_FOR_DATA);
  if (CONCAT31(extraout_var_00,_Var1) == 0) {
    _Var1 = mac_is_op_pending(dev,MAC_OPERATION_ACTIVE_SCAN);
    if (CONCAT31(extraout_var_01,_Var1) != 0) {
      op = MAC_OPERATION_ACTIVE_SCAN;
      goto _L0;
    }
    _Var1 = mac_is_op_pending(dev,MAC_OPERATION_ED_SCAN);
    if (CONCAT31(extraout_var_02,_Var1) != 0) {
      op = MAC_OPERATION_ED_SCAN;
      goto _L0;
    }
    _Var1 = mac_is_op_pending(dev,MAC_OPERATION_TRANSMIT_ASSO_REQ);
    if (CONCAT31(extraout_var_03,_Var1) != 0) {
      op = MAC_OPERATION_TRANSMIT_ASSO_REQ;
      goto _L0;
    }
    _Var1 = mac_is_op_pending(dev,MAC_OPERATION_TRANSMIT_BEACON);
    if (CONCAT31(extraout_var_04,_Var1) != 0) {
      op = MAC_OPERATION_TRANSMIT_BEACON;
      goto _L0;
    }
    _Var1 = mac_is_op_pending(dev,MAC_OPERATION_TRANSMIT_INDIRECT);
    if (CONCAT31(extraout_var_05,_Var1) != 0) {
      op = MAC_OPERATION_TRANSMIT_INDIRECT;
      goto _L0;
    }
    _Var1 = mac_is_op_pending(dev,MAC_OPERATION_TRANSMIT_POLL);
    if (CONCAT31(extraout_var_06,_Var1) != 0) {
      op = MAC_OPERATION_TRANSMIT_POLL;
      goto _L0;
    }
    _Var1 = mac_is_op_pending(dev,MAC_OPERATION_TRANSMIT_DATA_DIRECT);
    if (CONCAT31(extraout_var_07,_Var1) != 0) {
      op = MAC_OPERATION_TRANSMIT_DATA_DIRECT;
      goto _L0;
    }
_L0:
    mac_do_idle(dev);
  }
  else {
    op = MAC_OPERATION_WAITING_FOR_DATA;
_L0:
    mac_clr_pending_op(dev,op);
    (dev->ctx).cur_op = (uint8_t)op;
    mac_stop_timer(dev);
    if (op == MAC_OPERATION_TRANSMIT_ASSO_REQ) {
      mac_set_state(dev,MAC_STATE_ASSOCIATING);
    }
    else {
      if (op < MAC_OPERATION_TRANSMIT_DATA_DIRECT) {
        if (op == MAC_OPERATION_ACTIVE_SCAN) {
          mac_set_state(dev,MAC_STATE_SCANNING);
          mac_do_active_scan(dev);
          return;
        }
        if (op == MAC_OPERATION_ED_SCAN) {
          mac_set_state(dev,MAC_STATE_SCANNING);
          mac_do_ed_scan(dev);
          return;
        }
        if (op != MAC_OPERATION_IDLE) goto _L0;
        goto _L0;
      }
      if (op == MAC_OPERATION_WAITING_FOR_DATA) {
        mac_pal_receive((dev->ctx).phy_channel_page,(dev->ctx).phy_channel);
        mac_start_timer(dev,(short)(((dev->pib).max_frame_total_wait_time + 0x3bf) / 0x3c0) + 1);
        return;
      }
      if (MAC_OPERATION_WAITING_FOR_DATA < op) goto _L0;
      for (op = op - MAC_OPERATION_TRANSMIT_DATA_DIRECT; MAC_OPERATION_ACTIVE_SCAN < op;
          op = op - MAC_OPERATION_TRANSMIT_BEACON) {
_L0:
        __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x3c6,"mac_perform_next_op",&_L0);
_L0:
      }
    }
    mac_do_transmit(dev);
  }
  return;
}

