/*
 *
 * Tencent is pleased to support the open source community by making
 * Hippy available.
 *
 * Copyright (C) 2019 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#if defined(__ANDROID__) || defined(_WIN32)
#  include "bridge_runtime.h"
#elif __APPLE__
#  include "bridge/bridge_runtime.h"
#  include "common_header.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

enum class NetworkEventType {
  kRequestWillBeSent,
  kResponseReceived,
  kLoadingFinished
};

EXTERN_C int64_t InitJSFrameworkFFI(const char16_t* global_config, int32_t single_thread_mode,
                                    int32_t bridge_param_json, int32_t is_dev_module, int64_t group_id,
                                    uint32_t vfs_if, uint32_t dom_manager_id,
                                    int32_t engine_id, int32_t callback_id, uint32_t devtools_id);

EXTERN_C int32_t RunScriptFromFileFFI(int32_t engine_id, const char16_t* file_path, const char16_t* script_name,
                                      const char16_t* code_cache_dir, int32_t can_use_code_cache, int32_t callback_id);

EXTERN_C int32_t RunScriptFromAssetsFFI(int32_t engine_id, const char16_t* asset_name, const char16_t* code_cache_dir,
                                        int32_t can_use_code_cache, const char16_t* asset_str_char,
                                        int32_t callback_id);

EXTERN_C int32_t RunScriptFromUriFFI(int32_t engine_id,
                                     uint32_t vfs_id,
                                     const char16_t *uri,
                                     const char16_t *code_cache_dir,
                                     int32_t can_use_code_cache,
                                     int32_t is_local_file,
                                     int32_t callback_id);

EXTERN_C void LoadInstanceFFI(int32_t engine_id,
                              const char *params, int32_t params_length);

EXTERN_C void UnloadInstanceFFI(int32_t engine_id,
                                const char *params, int32_t params_length);

EXTERN_C void CallFunctionFFI(int32_t engine_id, const char16_t* action, const char* params, int32_t params_length, int32_t callback_id);

EXTERN_C const char* GetCrashMessageFFI();

EXTERN_C void DestroyFFI(int32_t engine_id, int32_t callback_id, int32_t is_reload);

EXTERN_C void NotifyNetworkEvent(int32_t engine_id, const char16_t* request_id, int32_t event_type, const char16_t* response, const char16_t* extra);

EXTERN_C void DoBindDomAndRender(uint32_t dom_manager_id, int32_t engine_id, uint32_t render_id);

EXTERN_C void DoConnectRootViewAndRuntime(int32_t engine_id, uint32_t root_id);

EXTERN_C void OnNetworkRequestInvoke(int32_t engine_id,
                                     const char16_t *request_id,
                                     const uint8_t *rep_meta_data,
                                     int32_t rep_meta_data_length);

EXTERN_C void OnNetworkResponseInvoke(int32_t engine_id,
                                      const char16_t *request_id,
                                      const uint8_t *rsp_meta_data,
                                      int32_t rsp_meta_data_length);

EXTERN_C uint32_t CreateDevtoolsFFI(const char16_t* char_data_dir,
                                    const char16_t* char_ws_url);

EXTERN_C void DestroyDevtoolsFFI(uint32_t devtools_id, int32_t is_reload);

#ifdef __cplusplus
}
#endif
