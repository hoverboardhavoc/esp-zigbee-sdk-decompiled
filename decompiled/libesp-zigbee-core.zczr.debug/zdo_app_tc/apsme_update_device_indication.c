/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_tc.o -> apsme_update_device_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void apsme_update_device_indication(apsme_update_device_ind_t *ind)

{
  undefined4 *puVar1;
  apsme_upddev_status_t aVar2;
  undefined1 uVar3;
  int iVar4;
  void *__src;
  ezb_zdo_tc_action_t tc_action;
  undefined4 uStack_3c;
  apsme_transport_key_req_t tk_req;
  
  uStack_3c = 0;
  tk_req.dst_address.field_0.u64._0_4_ = 0;
  tk_req.dst_address.field_0.u64._4_4_ = 0;
  tk_req._8_4_ = 0;
  tk_req.field_2._3_4_ = 0;
  tk_req.field_2._7_4_ = 0;
  tk_req.field_2._11_4_ = 0;
  tk_req.field_2._15_4_ = 0;
  tk_req.field_2._19_4_ = 0;
  tk_req._32_4_ = 0;
  tk_req.tunnel_address.field_0.u64._2_2_ = 0;
  aVar2 = ind->status;
  if (aVar2 == '\x02') {
    aps_forget_device(ind->device_shortaddr,&ind->device_address);
    tc_action = '\0';
  }
  else {
    if (aVar2 == '\x03') {
      iVar4 = aps_secur_is_centralized();
      if (iVar4 == 0) {
        tc_action = '\x02';
        goto _L0;
      }
    }
    else if (aVar2 != '\x01') {
      tc_action = '\0';
      goto _L0;
    }
    iVar4 = aps_secur_key_pair_find_or_create(&ind->device_address);
    if (iVar4 == 0) {
      tc_action = '\x02';
    }
    else if ((*(ushort *)(iVar4 + 0x34) & 6) == 2) {
      tc_action = '\x02';
    }
    else {
      iVar4 = aps_secur_tc_setup_key_pair();
      if (iVar4 == 0) {
        tk_req.dst_address.field_0.u8[4] = 1;
        puVar1 = (undefined4 *)((int)&ind->field_0 + 4);
        tk_req.field_2._21_2_ = *(undefined2 *)&ind->field_0;
        tk_req.tunnel_address.field_0.u64._0_2_ = *(undefined2 *)puVar1;
        tk_req.field_2._23_2_ = (short)((uint)*(undefined4 *)&ind->field_0 >> 0x10);
        tk_req.tunnel_address.field_0.u64._2_2_ = (undefined2)((uint)*puVar1 >> 0x10);
        uStack_3c = *(undefined4 *)&(ind->device_address).field_0;
        tk_req.dst_address.field_0.u64._0_4_ =
             *(undefined4 *)((int)&(ind->device_address).field_0 + 4);
        uVar3 = nwk_secur_get_current_key_seq();
        tk_req.field_2.nwk.key[0xc] = uVar3;
        __src = (void *)nwk_secur_get_key_by_seq();
        memcpy((void *)((int)&tk_req.dst_address.field_0 + 5),__src,0x10);
        iVar4 = apsme_transport_key_request(&uStack_3c);
        if (iVar4 == 0) {
          tc_action = '\0';
        }
        else {
          log_write(2,"zdo_app_tc.c","TransportKey failed(0x%x)",iVar4);
          tc_action = '\x02';
        }
      }
      else {
        tc_action = '\x01';
      }
    }
  }
_L0:
  zdo_tc_put_device_update_signal(ind,tc_action);
  return;
}

