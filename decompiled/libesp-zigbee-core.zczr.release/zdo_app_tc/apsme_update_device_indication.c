/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_tc.o -> apsme_update_device_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: tk_req */
/* WARNING: Unknown calling convention */

void apsme_update_device_indication(apsme_update_device_ind_t *ind)

{
  undefined4 *puVar1;
  apsme_upddev_status_t aVar2;
  ezb_shortaddr_t eVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  int iVar8;
  void *__src;
  undefined1 uVar9;
  undefined2 local_50;
  undefined1 auStack_4e [2];
  zdo_app_signal_t app_signal;
  apsme_transport_key_req_t tk_req;
  
  memset(app_signal.parameters + 0xe,0,0x2a);
  aVar2 = ind->status;
  if (aVar2 == '\x02') {
    aps_forget_device(ind->device_shortaddr,&ind->device_address);
_L0:
    uVar9 = 0;
  }
  else {
    if (aVar2 == '\x03') {
      iVar8 = aps_secur_is_centralized();
      if (iVar8 != 0) goto _L0;
    }
    else {
      if (aVar2 != '\x01') goto _L0;
_L0:
      iVar8 = aps_secur_key_pair_find_or_create(&ind->device_address);
      if ((iVar8 != 0) && ((*(ushort *)(iVar8 + 0x34) & 6) != 2)) {
        iVar8 = aps_secur_tc_setup_key_pair();
        uVar9 = 1;
        if (iVar8 != 0) goto _L0;
        tk_req.dst_address.field_0.u8[4] = '\x01';
        tk_req.field_2._21_2_ = *(undefined2 *)&ind->field_0;
        puVar1 = (undefined4 *)((int)&ind->field_0 + 4);
        tk_req.tunnel_address.field_0.u64._0_2_ = *(undefined2 *)puVar1;
        tk_req.field_2._23_2_ = (undefined2)((uint)*(undefined4 *)&ind->field_0 >> 0x10);
        tk_req.tunnel_address.field_0.u64._2_2_ = (undefined2)((uint)*puVar1 >> 0x10);
        unique0x1000004b = *(undefined4 *)&(ind->device_address).field_0;
        tk_req.dst_address.field_0.u64._0_4_ =
             *(undefined4 *)((int)&(ind->device_address).field_0 + 4);
        tk_req.field_2.nwk.key[0xc] = nwk_secur_get_current_key_seq();
        __src = (void *)nwk_secur_get_key_by_seq();
        memcpy((void *)((int)&tk_req.dst_address.field_0 + 5),__src,0x10);
        iVar8 = apsme_transport_key_request(app_signal.parameters + 0xe);
        if (iVar8 == 0) goto _L0;
        log_write(2,"zdo_app_tc.c","TransportKey failed(0x%x)",iVar8);
      }
    }
    uVar9 = 2;
  }
_L0:
  memset(auStack_4e,0,0x10);
  local_50 = 7;
  puVar7 = (undefined1 *)zdo_app_signal_get_params(&local_50);
  puVar1 = (undefined4 *)((int)&(ind->device_address).field_0 + 4);
  uVar4 = *(undefined2 *)puVar1;
  uVar5 = *(undefined4 *)&(ind->device_address).field_0;
  uVar6 = *puVar1;
  *puVar7 = (char)*(undefined2 *)&(ind->device_address).field_0;
  puVar7[1] = (char)((uint)uVar5 >> 8);
  puVar7[3] = (char)((uint)uVar5 >> 0x18);
  puVar7[5] = (char)((uint)uVar6 >> 8);
  puVar7[7] = (char)((uint)uVar6 >> 0x18);
  eVar3 = ind->device_shortaddr;
  puVar7[2] = (char)((uint)uVar5 >> 0x10);
  puVar7[4] = (char)uVar4;
  puVar7[6] = (char)((uint)uVar6 >> 0x10);
  *(ezb_shortaddr_t *)(puVar7 + 8) = eVar3;
  puVar7[10] = ind->status;
  *(undefined2 *)(puVar7 + 0xc) = 0xffff;
  nwk_address_short_by_extended(ind,puVar7 + 0xc);
  puVar7[0xb] = uVar9;
  zdo_app_put_signal(&local_50);
  return;
}

