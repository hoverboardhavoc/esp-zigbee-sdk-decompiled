/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> apsme_transport_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void apsme_transport_key_indication(apsme_transport_key_ind_t *ind)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint error;
  undefined4 uStack_1c;
  apsme_verify_key_req_t vk_req;
  
  if (ind->key_type == '\x01') {
    iVar2 = core_globals_get();
    if ((*(char *)(iVar2 + 0xd5c) == '\x01') || (iVar2 = nwk_secur_is_authenticated(), iVar2 != 0))
    {
      nwk_secur_set_key(&ind->field_2,(ind->field_2).nwk.key_seq);
    }
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0xd5c) != '\x01') {
      return;
    }
    nwk_pim_stop_fast_poll();
    iVar2 = nwk_is_device_zed();
    if ((iVar2 != 0) && (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x9ee) == '\0')) {
      nwk_pim_stop_poll();
    }
    cVar1 = nwk_secur_is_authenticated();
    if (cVar1 == '\x01') {
      __assert_func("//build/esp-zigbee/src/core/zdo/zdo_app_secur.c",0xef,
                    "apsme_transport_key_indication","!nwk_secur_is_authenticated()");
    }
    else {
      iVar2 = nwk_secur_switch_key((ind->field_2).nwk.key_seq);
      if (iVar2 == 0) {
        zdo_secur_finish_state(0);
        return;
      }
    }
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_app_secur.c",0xf1,
                  "apsme_transport_key_indication","(nwk_secur_switch_key(ind->nwk.key_seq)) == 0");
  }
  else if (ind->key_type != '\x04') {
    return;
  }
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xd5c) == '\x02') {
    iVar2 = aps_secur_is_addr_tc(ind);
    if (iVar2 == 0) {
      __assert_func("//build/esp-zigbee/src/core/zdo/zdo_app_secur.c",0xf8,
                    "apsme_transport_key_indication","aps_secur_is_addr_tc(&ind->src_address)");
_L0:
      iVar2 = __assert_func("//build/esp-zigbee/src/core/zdo/zdo_app_secur.c",0x106,
                            "apsme_transport_key_indication",
                            "(apsme_verify_key_request(&vk_req)) == 0");
      if ((*(char *)(iVar2 + 8) == '\x04') &&
         (iVar3 = core_globals_get(), *(char *)(iVar3 + 0xd5c) == '\x03')) {
        nwk_pim_stop_fast_poll();
        if (*(byte *)(iVar2 + 9) == 0) {
          error = 0;
        }
        else {
          error = *(byte *)(iVar2 + 9) | 0x300;
        }
        zdo_secur_finish_state(error);
      }
      return;
    }
    iVar2 = aps_secur_get_key_pair_by_addr(ind);
    if ((iVar2 != 0) && ((*(ushort *)(iVar2 + 0x34) & 6) != 2)) {
      *(ushort *)(iVar2 + 0x34) = *(ushort *)(iVar2 + 0x34) & 0xfff9 | 2;
      memcpy((void *)(iVar2 + 0x12),&ind->field_2,0x10);
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0x9b8) = 0;
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xd5c) = 3;
      vk_req.dst_address.field_0.u8[4] = '\x04';
      uStack_1c = *(undefined4 *)&(ind->src_address).field_0;
      vk_req.dst_address.field_0.u64._0_4_ = *(undefined4 *)((int)&(ind->src_address).field_0 + 4);
      iVar2 = apsme_verify_key_request(&uStack_1c);
      if (iVar2 != 0) goto _L0;
      iVar2 = core_globals_get();
      iVar3 = core_globals_get();
      milli_timer_start(iVar2 + 0xd60,(*(ushort *)(iVar3 + 0x9ba) & 0x1f) * 1000);
    }
  }
  return;
}

