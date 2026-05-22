/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_network_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_status(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  nwk_network_status_cmd_t nStack_14;
  nwk_network_status_cmd_t cmd;
  
  iVar2 = nwk_is_joined();
  if (iVar2 == 0) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
  }
  else {
    iVar2 = nwk_secur_get_seclevel();
    if ((ushort)(iVar2 != 0) == (msg->flags >> 1 & 1)) {
      nStack_14.status_code = '\0';
      nStack_14.target_addr = 0;
      nStack_14.command_id = '\0';
      sVar1 = zmsg_get_offset(msg);
      zmsg_read_bytes(msg,sVar1 + 1,4,&nStack_14);
      uVar3 = (uint)nStack_14 & 0xff;
      if (uVar3 == 0xd) {
        nwk_fwd_purge_ex(0xffff,nwk_filter_address_conflict_status,&nStack_14);
      }
      else if (uVar3 < 0xe) {
        if ((2 < uVar3) && (1 < (uVar3 - 0xb & 0xff))) goto _L0;
      }
      else if (uVar3 != 0x13) goto _L0;
      nwk_handle_network_status_local(&nStack_14);
    }
  }
_L0:
  zmsg_free(msg);
  return;
}

