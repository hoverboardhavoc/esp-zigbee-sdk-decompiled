/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_convert_beacon_to_beacon_notify_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_convert_beacon_to_beacon_notify_ind
                    (mac_frame_t *beacon_frame,mac_beacon_notify_ind_t *ind)

{
  ezb_shortaddr_t eVar1;
  ezb_shortaddr_t eVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ezb_panid_t eVar5;
  undefined1 uVar6;
  _Bool _Var7;
  undefined3 extraout_var;
  ezb_err_t eVar8;
  mac_superframe_spec_t *pmVar9;
  
  memset(ind,0,0x1c);
  if (beacon_frame == (mac_frame_t *)0x0) {
    eVar8 = 2;
  }
  else {
    _Var7 = mac_is_valid_beacon_frame(beacon_frame);
    if (CONCAT31(extraout_var,_Var7) == 0) {
      eVar8 = 0x10;
    }
    else {
      pmVar9 = (mac_superframe_spec_t *)(beacon_frame->mpl).buf;
      ind->beacon_type = ((beacon_frame->mhr).fcf & 0x3000) == 0x2000;
      if ((beacon_frame->mhr).src_addr.addr_mode == '\0') {
        eVar8 = 0x10;
      }
      else {
        uVar6 = (beacon_frame->mhr).src_addr.field_0x1;
        eVar1 = (beacon_frame->mhr).src_addr.u.short_addr;
        eVar2 = (beacon_frame->mhr).src_addr.u.group_addr.bcast;
        uVar3 = *(undefined2 *)((int)&(beacon_frame->mhr).src_addr.u + 4);
        uVar4 = *(undefined2 *)((int)&(beacon_frame->mhr).src_addr.u + 6);
        (ind->pan_descriptor).coord_addr.addr_mode = (beacon_frame->mhr).src_addr.addr_mode;
        (ind->pan_descriptor).coord_addr.field_0x1 = uVar6;
        (ind->pan_descriptor).coord_addr.u.short_addr = eVar1;
        (ind->pan_descriptor).coord_addr.u.group_addr.bcast = eVar2;
        *(undefined2 *)((int)&(ind->pan_descriptor).coord_addr.u + 4) = uVar3;
        *(undefined2 *)((int)&(ind->pan_descriptor).coord_addr.u + 6) = uVar4;
        eVar5 = (beacon_frame->mhr).src_panid;
        (ind->pan_descriptor).coord_panid = eVar5;
        if (eVar5 == 0xffff) {
          (ind->pan_descriptor).coord_panid = (beacon_frame->mhr).dst_panid;
        }
        (ind->pan_descriptor).channel_number = beacon_frame->from->channel;
        (ind->pan_descriptor).lqi = (beacon_frame->from->info).tx.max_csma_backoffs;
        (ind->pan_descriptor).rssi = (beacon_frame->from->info).tx.max_frame_retries;
        (ind->pan_descriptor).superframe_spec = *pmVar9;
        ind->bsn = (beacon_frame->mhr).seq_num;
        ind->beacon_payload = (uint8_t *)(pmVar9 + 2);
        ind->beacon_payload_length = (beacon_frame->mpl).len + 0xfc;
        eVar8 = 0;
      }
    }
  }
  return eVar8;
}

