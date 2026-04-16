/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_do_ed_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_do_ed_scan(mac_device *dev)

{
  uint8_t uVar1;
  uint uVar2;
  ezb_err_t eVar3;
  uint32_t uVar4;
  int iVar5;
  active_scan_callback p_Var6;
  
  eVar3 = mac_update_scan_channel(dev);
  if (eVar3 == 0) {
    uVar2 = (dev->ctx).scan_channels.u32 >> 0x1b;
    uVar1 = (dev->ctx).scan_channel;
    uVar4 = mac_scan_duration_to_msec((dev->ctx).scan_duration);
    if ((*(uint *)&(dev->pib).transaction_persistence_time >> 0x11 & 1) == 0) {
      mac_pal_receive(uVar2,uVar1);
    }
    iVar5 = mac_pal_energy_detect(uVar2,uVar1,uVar4 & 0xffff);
    if (iVar5 == 0) {
      return;
    }
  }
  mac_finish_op(dev);
  mac_set_state(dev,MAC_STATE_NORMAL);
  p_Var6 = (dev->ctx).field_7.active_scan_result_handler;
  if (p_Var6 != (active_scan_callback)0x0) {
    (*p_Var6)((active_scan_result_t *)0x0,(dev->ctx).scan_user_ctx);
  }
  mac_perform_next_op(dev);
  return;
}

