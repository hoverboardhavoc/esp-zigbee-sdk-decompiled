/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_packet_rsp_handler(undefined1 *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (undefined1 *)0x0) {
    iVar3 = 0x80;
  }
  else {
    iVar2 = zdo_packet_ctx_list_find_entry(*param_1);
    if (iVar2 == 0) {
      iVar3 = 0xfe;
    }
    else {
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 0x18);
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar2 + 0x1c);
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar2 + 0x20);
      uVar1 = *(ushort *)(param_1 + 6);
      if (uVar1 < 0x8020) {
        iVar3 = zdo_device_service_discovery_rsp_handler(param_1);
      }
      else if (uVar1 < 0x8030) {
        iVar3 = zdo_bind_mgmt_rsp_handler(param_1);
      }
      else {
        if (0x803f < uVar1) {
          return 0x84;
        }
        iVar3 = zdo_nwk_mgmt_rsp_handler(param_1);
      }
      if ((iVar3 == 0) &&
         (*(byte *)(iVar2 + 0x14) = *(byte *)(iVar2 + 0x14) | 1, *(char *)(iVar2 + 0x18) == '\x01'))
      {
        zdo_packet_ctx_list_remove_entry(iVar2);
        zdo_packet_ctx_free_entry(iVar2);
      }
    }
  }
  return iVar3;
}

