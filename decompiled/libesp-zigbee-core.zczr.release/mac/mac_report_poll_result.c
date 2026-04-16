/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_report_poll_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_report_poll_result(mac_device *dev,mac_status_t status)

{
  mac_device *dev_00;
  undefined3 in_register_0000202d;
  mac_operation_t scan_op;
  channel_page_t in_a2;
  uint16_t in_a3;
  mac_associate_cnf_t mStack_14;
  mac_associate_cnf_t asso_cnf;
  
  dev_00 = (mac_device *)
           mac_pal_set_rx_when_idle(*(uint *)&(dev->pib).transaction_persistence_time >> 0x11 & 1);
  if ((dev->ctx).state == '\x02') {
    if (CONCAT31(in_register_0000202d,status) == 0) {
      mac_scan(dev_00,scan_op,in_a2,in_a3);
    }
    mStack_14.asso_shortaddr = 0xffff;
    mStack_14.status = status;
    mac_finish_association(dev,&mStack_14);
  }
  else {
    mStack_14.asso_shortaddr = CONCAT11(mStack_14.asso_shortaddr._1_1_,status);
    nwk_mm_poll_confirm((dev->ctx).iface_id,&mStack_14);
  }
  return;
}

