/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mlme_scan_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_mlme_scan_request(mac_interface_t *iface,mac_scan_req_t *req)

{
  byte bVar1;
  uint8_t uVar2;
  uint uVar3;
  _Bool _Var4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  mac_device *dev;
  uint uVar5;
  uint uVar6;
  anon_union_4_2_0921b8ba_for_cb_u aVar7;
  uint uVar8;
  void *pvVar9;
  ezb_err_t eVar10;
  
  bVar1 = req->scan_type;
  dev = (mac_device *)iface->dev;
  if (bVar1 == 1) {
    pvVar9 = req->user_ctx;
    aVar7 = req->cb_u;
    uVar2 = req->scan_duration;
    uVar5 = (req->scan_channels).u32;
    if ((*(uint *)&(dev->ctx).field_0x70 & 1) == 0) {
      return 3;
    }
    _Var4 = mac_can_scan(dev);
    eVar10 = 9;
    if (CONCAT31(extraout_var,_Var4) != 0) {
      (dev->ctx).scan_channel = 0xff;
      uVar3 = uVar5 >> 0x1b;
      uVar6 = (dev->pib).supported_channel_page.u32;
      (dev->ctx).scan_channels.u32 = (dev->ctx).scan_channels.u32 & 0x7ffffff | uVar3 << 0x1b;
      (dev->ctx).field_7 = (anon_union_4_2_1421745a_for_mac_context_s_7)aVar7;
      (dev->ctx).scan_user_ctx = pvVar9;
      (dev->ctx).scan_duration = uVar2;
      uVar8 = 0;
      if (uVar6 >> 0x1b == uVar3) {
        uVar8 = uVar6 & 0x7ffffff & uVar5 & 0x7ffffff;
      }
      (dev->ctx).scan_channels.u32 = (dev->ctx).scan_channels.u32 & 0xf8000000 | uVar8;
      mac_start_op(dev,MAC_OPERATION_ACTIVE_SCAN);
      eVar10 = 0;
    }
    return eVar10;
  }
  if (bVar1 < 2) {
    pvVar9 = req->user_ctx;
    aVar7 = req->cb_u;
    uVar2 = req->scan_duration;
    uVar5 = (req->scan_channels).u32;
    if ((*(uint *)&(dev->ctx).field_0x70 & 1) == 0) {
      return 3;
    }
    _Var4 = mac_can_scan(dev);
    eVar10 = 9;
    if (CONCAT31(extraout_var_00,_Var4) != 0) {
      (dev->ctx).scan_channel = 0xff;
      uVar3 = uVar5 >> 0x1b;
      uVar6 = (dev->pib).supported_channel_page.u32;
      (dev->ctx).scan_channels.u32 = (dev->ctx).scan_channels.u32 & 0x7ffffff | uVar3 << 0x1b;
      (dev->ctx).field_7 = (anon_union_4_2_1421745a_for_mac_context_s_7)aVar7;
      (dev->ctx).scan_user_ctx = pvVar9;
      (dev->ctx).scan_duration = uVar2;
      uVar8 = 0;
      if (uVar6 >> 0x1b == uVar3) {
        uVar8 = uVar6 & 0x7ffffff & uVar5 & 0x7ffffff;
      }
      (dev->ctx).scan_channels.u32 = (dev->ctx).scan_channels.u32 & 0xf8000000 | uVar8;
      mac_start_op(dev,MAC_OPERATION_ED_SCAN);
      eVar10 = 0;
    }
    return eVar10;
  }
  return (-(uint)(2 < (byte)(bVar1 - 2)) & 0xfffffffc) + 6;
}

