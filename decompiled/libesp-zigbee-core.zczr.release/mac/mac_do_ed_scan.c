/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_do_ed_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_do_ed_scan(mac_device *dev)

{
  byte bVar1;
  uint8_t uVar2;
  ezb_err_t eVar3;
  int iVar4;
  active_scan_callback p_Var5;
  uint uVar6;
  
  if (((*(uint *)&(dev->ctx).field_0x70 & 1) != 0) &&
     (eVar3 = mac_update_scan_channel(dev), eVar3 == 0)) {
    bVar1 = (dev->ctx).scan_duration;
    uVar2 = (dev->ctx).scan_channel;
    uVar6 = (dev->ctx).scan_channels.u32 >> 0x1b;
    if (-1 < *(int *)&(dev->pib).transaction_persistence_time << 0xe) {
      mac_pal_receive(uVar6);
    }
    iVar4 = mac_pal_energy_detect
                      (uVar6,uVar2,(uint)(((1 << (bVar1 & 0x1f)) + 1) * 0x3c00) / 1000 & 0xffff);
    if (iVar4 == 0) {
      return;
    }
  }
  p_Var5 = (dev->ctx).field_7.active_scan_result_handler;
  (dev->ctx).cur_op = '\0';
  (dev->ctx).state = '\0';
  if (p_Var5 != (active_scan_callback)0x0) {
    (*p_Var5)((active_scan_result_t *)0x0,(dev->ctx).scan_user_ctx);
  }
  mac_perform_next_op(dev);
  return;
}

